#ifndef REMOTEVIEW_H
#define REMOTEVIEW_H

#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QMutex>
#include <QMutexLocker>
#include <QMenu>
#include <QAction>
#include <QLineEdit>
#include <QTextBrowser>
#include <QPlainTextEdit>
#include <QContextMenuEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class RemoteView;
}
QT_END_NAMESPACE

class RemoteView : public QDialog
{
    Q_OBJECT

public:
    RemoteView(QWidget *parent = nullptr);
    ~RemoteView();

protected:
    // 重写父类的eventfilter方法
    bool eventFilter(QObject *watched, QEvent *event);
    // 重写父类方法
    void contextMenuEvent(QContextMenuEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void RequestRootDir();

    void onBackButtonClicked();

    QUrl CombineUrls(const QUrl& base_url, const QUrl& relative_url);

private slots:
    void on_btn_request_clicked();
    void onDownloadFinished();
    void onReplyFinished(QNetworkReply *reply);
    void onLinkClicked(const QUrl &url);
    void onViewFile();
    void onDownloadFile();
    void onCustomContextMenuRequested(const QPoint &pos);

private:
    QString base_url_ = "";
    // QString ip = "192.168.1.66";
    QString ip = "127.0.0.1";
    QString port = "8000";
    QString url = "";
    QMutex mutex_;
    QNetworkAccessManager *networkManager;      // 普通请求 //
    QNetworkAccessManager *downloadManager;     // 下载请求 //

    QMenu *contextMenu;
    QAction *viewAction;
    QAction *downloadAction;
    QString selectedFileUrl;

    QNetworkReply *currentReply;

private:
    QMenu *mExitMenu;   // 右键退出的菜单
    QAction *mExitAct;  // 退出行为 - 菜单项
    QAction *mReturnAct; // 返回行为 - 菜单项
    QPoint mOffset;     // 窗口移动时，鼠标与窗口左上角的偏移



private:
    Ui::RemoteView *ui;
};
#endif // REMOTEVIEW_H
