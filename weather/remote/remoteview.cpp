#include "remoteview.h"
#include "./ui_remoteview.h"

#include <QFile>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QRegularExpression>

#include <QStringConverter>

RemoteView::RemoteView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoteView)
{
    ui->setupUi(this);

    // 构建右键菜单
    mExitMenu  = new QMenu(this);
    mExitAct = new QAction();
    mReturnAct = new QAction();

    mExitAct->setText("退出");
    mExitAct->setIcon(QIcon(":/res/close.png"));
    mReturnAct->setText("返回菜单"); // 添加返回动作文本
    mReturnAct->setIcon(QIcon(":/res/close.png")); // 添加返回动作图标

    // 将动作添加到右键菜单
    mExitMenu->addAction(mExitAct);
    mExitMenu->addAction(mReturnAct); // 将返回动作添加到右键菜单

    // 连接返回动作的信号和槽
    connect(mExitAct, &QAction::triggered, this, [=]{
        qApp->exit(0);
    });

    connect(mReturnAct, &QAction::triggered, this, [=]{
        // 隐藏当前窗口（即 MainWindow）
        hide();
        // 显示主窗口（即 MainWidget）
        parentWidget()->show();
    });


    base_url_ = QString("http://%1:%2").arg(ip, port);

    contextMenu = new QMenu(this);
    viewAction = new QAction("View", this);
    downloadAction = new QAction("Download", this);
    contextMenu->addAction(viewAction);
    contextMenu->addAction(downloadAction);

    connect(viewAction, SIGNAL(triggered()), this, SLOT(onViewFile()));
    connect(downloadAction, SIGNAL(triggered()), this, SLOT(onDownloadFile()));

    networkManager = new QNetworkAccessManager(this);
    downloadManager = new QNetworkAccessManager(this);

    connect(networkManager, &QNetworkAccessManager::finished, this, &RemoteView::onReplyFinished);
    connect(downloadManager, &QNetworkAccessManager::finished, this, &RemoteView::onDownloadFinished);
    connect(ui->textbrowser_response, &QTextBrowser::anchorClicked, this, &RemoteView::onLinkClicked);
    connect(ui->textbrowser_response, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(onCustomContextMenuRequested(const QPoint &)));
    ui->textbrowser_response->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->textbrowser_response->viewport()->installEventFilter(this);

    // 添加返回父级目录的按钮
    connect(ui->btn_return, &QPushButton::clicked, this, &RemoteView::onBackButtonClicked);

    RequestRootDir();
}

RemoteView::~RemoteView()
{
    delete ui;
}

bool RemoteView::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->textbrowser_response->viewport() && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            QUrl url = ui->textbrowser_response->anchorAt(mouseEvent->pos());
            if (!url.toString().endsWith("/")) {
                // 最后一级文件，阻止跳转 //
                ui->textbrowser_response->setOpenLinks(false);
                return true;
            }
            else {
                ui->textbrowser_response->setOpenLinks(true);
            }
        }
    }
    return QDialog::eventFilter(watched, event);
}

void RemoteView::onViewFile()
{
    qDebug("onViewFile");

    QUrl requestUrl = CombineUrls(base_url_, selectedFileUrl);

    qDebug() << "OnViewFile: " << requestUrl.toString();

    QNetworkRequest request(requestUrl);
    currentReply = networkManager->get(request);
}

void RemoteView::onDownloadFile()
{
    qDebug("onDownloadFile");

    QUrl requestUrl = CombineUrls(base_url_, selectedFileUrl);

    QNetworkRequest request(requestUrl);
    currentReply = downloadManager->get(request);
}

void RemoteView::onCustomContextMenuRequested(const QPoint &pos)
{
    qDebug("onCustomContextMenuRequested");
    QTextCursor cursor = ui->textbrowser_response->cursorForPosition(pos);
    QTextCharFormat charFormat = cursor.charFormat();

    if (charFormat.isAnchor()) {
        selectedFileUrl = charFormat.anchorHref();
        contextMenu->exec(ui->textbrowser_response->mapToGlobal(pos));
        qDebug() << "selectedFileUrl: " << selectedFileUrl;
    } else {
        selectedFileUrl.clear();
    }
}

void RemoteView::RequestRootDir()
{
    base_url_ = QString("http://%1:%2").arg(ip, port);
    QNetworkRequest request(CombineUrls(base_url_, QString("/")));

    networkManager->get(request);
}

void RemoteView::onDownloadFinished()
{
    qDebug("handleDownloadFinished");
    if (currentReply->error() == QNetworkReply::NoError) {
        QByteArray fileData = currentReply->readAll();
        QString fileName = QFileInfo(currentReply->url().path()).fileName();
        QString savePath = QFileDialog::getSaveFileName(this, tr("Save File"), fileName);

        if (!savePath.isEmpty()) {
            QFile file(savePath);
            if (file.open(QIODevice::WriteOnly)) {
                file.write(fileData);
                file.close();
                qDebug() << "File saved successfully to" << savePath;
            } else {
                qDebug() << "Failed to save file to" << savePath;
            }
        }
    } else {
        qDebug() << "Download error:" << currentReply->errorString();
    }
    currentReply->deleteLater();
}

void RemoteView::onReplyFinished(QNetworkReply *reply)
{
    qDebug("onReplyFinished");
    QMutexLocker locker(&mutex_);
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QString contentType = reply->header(QNetworkRequest::ContentTypeHeader).toString();

        QString charset = "UTF-8"; // 默认编码 //
        QRegularExpression charsetRegex("charset=([\\w-]+)");
        QRegularExpressionMatch charsetMatch = charsetRegex.match(contentType);
        if (charsetMatch.hasMatch()) {
            charset = charsetMatch.captured(1);
        }

        // 使用 QStringConverter 代替 QTextCodec
        auto encoding = QStringConverter::encodingForName(charset.toLatin1());
        if (!encoding) {
            encoding = QStringConverter::Encoding::Utf8;
        }

        // 使用 QStringDecoder 进行解码
        QStringDecoder decoder(*encoding);
        QString response = decoder.decode(responseData);

        // 输出解码后的字符串
        // qDebug() << response;

        // Remove IP address pattern using regular expression //
        QRegularExpression ipRegex("\\b\\d{1,3}(?:\\.\\d{1,3}){3}\\b - /");
        response.replace(ipRegex, "");

        qDebug() << "contentType: " << contentType;
#if 1
        QString css = "body { font-size: 12pt; line-height: 1.5; font-weight: bold;}";
        ui->textbrowser_response->document()->setDefaultStyleSheet(css);

        if (!contentType.startsWith("text/html")/*contentType.startsWith("text/plain")*/) {
            ui->plaintextedit_response->setPlainText(response);
        } else {
            ui->textbrowser_response->setHtml(response);
        }
#else
        if (contentType.startsWith("text/html")) {
            // Filter directories and .txt files
            QRegularExpression linkRegex("<A HREF=\"([^\"]+)\">([^<]+)</A>");
            QRegularExpressionMatchIterator i = linkRegex.globalMatch(response);
            QString filteredResponse;

            while (i.hasNext()) {
                QRegularExpressionMatch match = i.next();
                QString url = match.captured(1);
                QString name = match.captured(2);
                if (url.endsWith("/") || url.endsWith(".txt")) {
                    filteredResponse += QString("<P><A HREF=\"%1\">%2</A></P>").arg(url, name);
                }
            }

            // Add CSS for font size and bold text
            QString styledResponse = QString(
                                         "<html>"
                                         "<head>"
                                         "<style>"
                                         "body { font-size: 12pt; font-weight: bold; line-height: 1.2; }"
                                         "a { font-size: 12pt; font-weight: bold; }"
                                         "</style>"
                                         "</head>"
                                         "<body>%1</body>"
                                         "</html>"
                                         ).arg(filteredResponse);

            ui->textbrowser_response->setHtml(styledResponse);
        } else if (contentType.startsWith("text/plain")) {
            ui->plaintextedit_response->setPlainText(response);
        } else {
            ui->textbrowser_response->setPlainText("This client only supports viewing directories and .txt files.");
        }
#endif
    } else {
        ui->textbrowser_response->setPlainText("Error: " + reply->errorString());
    }
    reply->deleteLater();
}

QUrl RemoteView::CombineUrls(const QUrl& base_url, const QUrl& relative_url) {
    return base_url.resolved(relative_url);
}

void RemoteView::onLinkClicked(const QUrl &url)
{
    qDebug("onLinkClicked");
    QUrl furl = CombineUrls(base_url_, url);
    qDebug() << furl.toString();

    // 确保只响应文件夹链接 //
    if (!url.toString().endsWith("/")) {
        qDebug() << "Non-directory link clicked, ignoring.";
        return;
    } else {
        base_url_ = furl.toString();
        qDebug() << "Update base_url_: " << base_url_;
    }

    QNetworkRequest request(furl);
    networkManager->get(request);
}

void RemoteView::onBackButtonClicked()
{
    qDebug("onBackButtonClicked");
    QUrl currentUrl(base_url_);
    QString path = currentUrl.path();

    // 去除最后一个路径段
    int lastSlashIndex = path.lastIndexOf('/', path.length() - 2);
    if (lastSlashIndex != -1) {
        path = path.left(lastSlashIndex + 1);
        QUrl parentUrl = currentUrl;
        parentUrl.setPath(path);

        qDebug() << "Navigating to parent directory:" << parentUrl.toString();

        QNetworkRequest request(parentUrl);
        networkManager->get(request);

        // 更新 base_url_ 为父级目录的 URL
        base_url_ = parentUrl.toString();
    } else {
        qDebug() << "Already at root directory.";
    }
}

void RemoteView::on_btn_request_clicked()
{
    RequestRootDir();
}


// 重写父类虚函数
// 父类中默认的实现  是忽略右键菜单事件
// 重写之后，就可以处理右键菜单
void RemoteView::contextMenuEvent(QContextMenuEvent *event)
{
    // 弹出右键菜单
    mExitMenu->exec(QCursor::pos());

    event->accept();
}

void RemoteView::mousePressEvent(QMouseEvent *event)
{
    mOffset =  event->globalPos() - this->pos();
}

void RemoteView::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - mOffset);
}
