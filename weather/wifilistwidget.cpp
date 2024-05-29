#include "wifilistwidget.h"
#include "ui_wifilistwidget.h"
#include <QDebug>
#include <QFile>
#include <QListWidgetItem>
#include <QRegularExpression>
#include "controlwidget.h"

extern devStatus sysDevStatus;

wifiListWidget::wifiListWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::wifiListWidget)
{
    ui->setupUi(this);
    wifiTimer = new QTimer();
    wifiTimer->start(5000);
    connect(wifiTimer,SIGNAL(timeout()),this,SLOT(timerTimeOut()));
    currentWifiExist=false;

    QVBoxLayout *wifiLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout(ui->widgetButton);
    QGridLayout *keyLayout = new QGridLayout(ui->widgetKeyboard);

    //setting keyboard GridLayout
    const QStringList buttonLabels = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
        "q", "w", "e", "r", "t", "y", "u", "i", "o", "p",
        "a", "s", "d", "f", "g", "h", "j", "k", "l","En",
        "Sh", "z", "x", "c", "v", "b", "n", "m", "De"," "
    };
    QString buttonStyle;
    buttonStyle= QString("QPushButton:pressed {background-color: rgb(255, 255, 255);}QPushButton {border-radius:5px;background-color: rgb(200, 200, 200);}");

    qDebug()<<buttonLabels.size();
    for (int i = 0; i < buttonLabels.size(); ++i) {
        keycap[i] = new QPushButton(buttonLabels.at(i), this);

        keycap[i]->setStyleSheet(buttonStyle);
        QSize s(25,40);
        keycap[i]->setFixedSize(s);
        keyLayout->addWidget(keycap[i], i / 10, i % 10);

        connect(keycap[i], &QPushButton::clicked, this, [=]() {
            onButtonClicked(keycap[i]->text());
        });
    }

    setLayout(keyLayout);

    wifiLayout->addWidget(ui->labelWifi);

    //setting wifiList QVBoxLayout
    wifiLayout->addWidget(ui->listWidgetWIFI);
    ui->listWidgetWIFI->addItem("linked:"+sysDevStatus.linkWifiSSID);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Enter password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    QString lineEllditStyle;
    buttonStyle= QString("background-color: rgb(200, 200, 200);");
    passwordLineEdit->setStyleSheet(lineEllditStyle);
    wifiLayout->addWidget(passwordLineEdit);

    QPushButton *connectButton = new QPushButton("Connect", this);
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    QPushButton *keyboardButton = new QPushButton("b", this);
    QPushButton *disconnectButton = new QPushButton("Dis", this);

    buttonStyle= QString("  QPushButton:pressed {background-color: rgb(255, 255, 255);}QPushButton {border-radius:2px;background-color: rgb(200, 200, 200);}");
    connectButton->setStyleSheet(buttonStyle);
    cancelButton->setStyleSheet(buttonStyle);
    keyboardButton->setStyleSheet(buttonStyle);
    disconnectButton->setStyleSheet(buttonStyle);

    QSize s1(25,25);
    keyboardButton->setFixedSize(s1);
    QSize s2(70,30);
    connectButton->setFixedSize(s2);
    QSize s3(70,30);
    cancelButton->setFixedSize(s3);

    QSize s4(40,25);
    disconnectButton->setFixedSize(s4);

    connect(connectButton, &QPushButton::clicked, this, &wifiListWidget::connectToWiFi);
    connect(cancelButton, &QPushButton::clicked, this, &wifiListWidget::keyBoardCancel);
    connect(keyboardButton, &QPushButton::clicked, this, &wifiListWidget::keyBoardAwaken);
    connect(disconnectButton, &QPushButton::clicked, this, &wifiListWidget::disconnectToWiFi);

    connect(passwordLineEdit, &QLineEdit::cursorPositionChanged, this, &wifiListWidget::keyBoardEdit);


    //setting button QHBoxLayout
    buttonLayout->addWidget(connectButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(keyboardButton);
    buttonLayout->addWidget(disconnectButton);

    setLayout(buttonLayout);

    wifiLayout->addWidget(ui->widgetButton);
    wifiLayout->addWidget(ui->widgetKeyboard);

    setLayout(wifiLayout);
    refreshWiFiList();

    keycapDev=LITTLE;
    keyBoardDev=KEYOFF;
    OtherDev=KEYOFF;
    setOtherStatus(OtherDev);
}

wifiListWidget::~wifiListWidget()
{
    delete ui;
}

void wifiListWidget::refreshWiFiList()
{
    // Clear existing items
    ui->listWidgetWIFI->clear();

    // Use a system command to get the list of available WiFi networks
    QProcess process;
    process.start("netsh wlan show networks mode=Bssid");
    process.waitForFinished(-1);
    QString result = process.readAllStandardOutput();

    // Extract network names from the result
    QStringList networkNames = result.split("\n");
    for (const QString &name : networkNames) {
        if (name.trimmed().startsWith("SSID")) {
            QString networkName = name.split(":").last().trimmed();
            if (!networkName.isEmpty()) {
                ui->listWidgetWIFI->addItem(networkName);
            }
        }
    }
}

void wifiListWidget::connectWifi()
{
    if(currentWifiExist==false)
    {
        QString networkName = ui->listWidgetWIFI->currentItem()->text();
        QString password =  passwordLineEdit->text();

        // Use wpa_passphrase command to generate WPA-PSK key
        QProcess passphraseProcess;
        passphraseProcess.start(QString("wpa_passphrase \"%1\" \"%2\"").arg(networkName).arg(password));
        passphraseProcess.waitForFinished(-1);
        QString config = passphraseProcess.readAllStandardOutput();
        qDebug()<<config;

        // Write configuration to wpa_supplicant.conf
        QFile configFile("/etc/wpa_supplicant.conf");
        if (configFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream out(&configFile);
            out << config;
            configFile.close();

            // Restart wpa_supplicant service
            QProcess restartProcess;;
            restartProcess.start("wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant.conf");
            restartProcess.waitForFinished(-1   );

            QString restartResult = restartProcess.readAllStandardOutput();
            // Display the result
            QMessageBox::information(this, "Connection Result", restartResult);

            restartProcess.start("udhcpc -i wlan0");
            restartProcess.waitForFinished(-1);
            restartResult = restartProcess.readAllStandardOutput();
            QMessageBox::information(this, "Connection Result", restartResult);

        } else {
            QMessageBox::warning(this, "Error", "Failed to open wpa_supplicant.conf for writing");
        }

    }
    else
    {
        // Restart wpa_supplicant service
        QProcess restartProcess;;
        restartProcess.start("wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant.conf");
        restartProcess.waitForFinished(-1);

        QString restartResult = restartProcess.readAllStandardOutput();
        // Display the result
        QMessageBox::information(this, "Connection Result", restartResult);

        restartProcess.start("udhcpc -i wlan0");
        restartProcess.waitForFinished(-1);
        restartResult = restartProcess.readAllStandardOutput();
        QMessageBox::information(this, "Connection Result", restartResult);
    }

    keyBoardDev=KEYOFF;
    setKeyboardStatus(keyBoardDev);
    passwordLineEdit->clear();

}

void wifiListWidget::setKeyboardStatus(keyBoardStatus s)
{
    if(s==KEYON)
    {
        if(currentWifiExist==true)
        {
            ui->widgetKeyboard->hide();
        }
        else
        {
            ui->widgetKeyboard->show();
        }

    }
    else
    {
        ui->widgetKeyboard->hide();
    }
}

void wifiListWidget::setOtherStatus(keyBoardStatus s)
{
    if(s==KEYON)
    {
        ui->widgetButton->show();
        if(currentWifiExist==true)
        {
            passwordLineEdit->hide();
        }
        else
        {
            passwordLineEdit->show();
        }
    }
    else
    {
        ui->widgetButton->hide();
        passwordLineEdit->hide();
    }
    keyBoardDev=s;
    setKeyboardStatus(s);
}

bool wifiListWidget::getWifiStatus()
{
    QProcess disProcess;
    disProcess.start("iw wlan0 link");
    disProcess.waitForFinished(-1);

    QByteArray output = disProcess.readAllStandardOutput();
    QString outputString = QString::fromLatin1(output);
    // 处理输出数据，提取网络名称并添加到列表中
    QStringList lines = outputString.split("\n");

    for (const QString &line : lines)
    {
        if (line.trimmed().startsWith("SSID"))
        {
            QString networkName = line.split(":").last().trimmed();
            if (!networkName.isEmpty())
            {
                sysDevStatus.linkWifiSSID=networkName;
            }
        }
    }

    if (outputString.contains("signal:"))
    {
        return true;
    } else
    {

        return false;
    }

}

void wifiListWidget::timerTimeOut()
{
    //    sysDevStatus.wifiLinkStatus =getWifiStatus();

    if(sysDevStatus.wifiLinkStatus==true)
    {
        ui->labelWifi->setStyleSheet("color: rgb(115, 210, 22);");
        ui->labelWifi->setText("linked:"+sysDevStatus.linkWifiSSID);
    }
    else
    {
        sysDevStatus.linkWifiSSID="noting";
        ui->labelWifi->setStyleSheet("color: rgb(239, 41, 41);");
        ui->labelWifi->setText("linked:"+sysDevStatus.linkWifiSSID);
    }
}

void wifiListWidget::connectToWiFi()
{
    connectWifi();
}

void wifiListWidget::disconnectToWiFi()
{
    if(getWifiStatus()==true)
    {
        QProcess disProcess;;
        disProcess.start("killall wpa_supplicant");
        disProcess.waitForFinished(-1);
        OtherDev=KEYOFF;
        setOtherStatus(OtherDev);
    }
}

void wifiListWidget::keyBoardEdit()
{
    keyBoardDev=KEYON;
    setKeyboardStatus(keyBoardDev);
}

void wifiListWidget::keyBoardCancel()
{
    OtherDev=KEYOFF;
    setOtherStatus(OtherDev);
}

void wifiListWidget::keyBoardAwaken()
{
    if(keyBoardDev==KEYON)
    {
        keyBoardDev=KEYOFF;
    }
    else if(keyBoardDev==KEYOFF)
    {
        keyBoardDev=KEYON;
    }
    setKeyboardStatus(keyBoardDev);
}


void wifiListWidget::onButtonClicked(const QString &text)
{
    if (text == "De")
    {
        passwordLineEdit->backspace();
    } else if (text == "Sh")
    {
        // 切换大小写
        if(keycapDev==BIG)
        {
            keycapDev=LITTLE;
        }
        else if(keycapDev==LITTLE)
        {
            keycapDev=BIG;
        }
        if(keycapDev==BIG)
        {
            QStringList buttonLabels =
                {
                    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
                    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P",
                    "A", "S", "D", "F", "G", "H", "J", "K", "L","En",
                    "Sh", "Z", "X", "C", "V", "B", "N", "M", "De"," "
                };

            for(int i=0;i<buttonLabels.size();i++)
            {
                keycap[i]->setText(buttonLabels.at(i));
            }
        }
        else
        {
            QStringList buttonLabels =
                {
                    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
                    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p",
                    "a", "s", "d", "f", "g", "h", "j", "k", "l","En",
                    "Sh", "z", "x", "c", "v", "b", "n", "m", "De"," "
                };
            for(int i=0;i<buttonLabels.size();i++)
            {
                keycap[i]->setText(buttonLabels.at(i));
            }
        }

    }else if (text == "En")
    {
        connectWifi();
    }
    else
    {
        passwordLineEdit->insert(text);

    }
}

void wifiListWidget::on_listWidgetWIFI_itemClicked(QListWidgetItem *item)
{
    //    QFile configFile("/etc/wpa_supplicant.conf");
    //    configFile.open(QIODevice::ReadOnly);
    //    QString output=configFile.readAll();
    //    configFile.close();

    //    // 定义匹配ssid的正则表达式
    //    QRegularExpression ssidRegex("ssid=\"([^\"]*)\"");

    //    // 在输入字符串中搜索匹配项
    //    QRegularExpressionMatch match = ssidRegex.match(output);

    //    // 如果找到匹配项
    //    if (match.hasMatch())
    //    {
    //       // 获取ssid的内容
    //       QString ssid = match.captured(1);
    //        if(ui->listWidgetWIFI->currentItem()->text()==ssid)
    //        {
    //            currentWifiExist=true;
    //            qDebug()<<ssid<<"is exist";
    //        }
    //        else
    //        {
    //           currentWifiExist=false;
    //        }
    //    }
    //    else
    //    {
    //       qDebug() << "SSID not found.";
    //    }

    if(OtherDev==KEYON)
    {
        OtherDev=KEYOFF;
    }
    else if(OtherDev==KEYOFF)
    {
        OtherDev=KEYON;
    }

    setOtherStatus(OtherDev);

}

void wifiListWidget::readProcessOutput()
{
    // 从进程的标准输出中读取数据
    QProcess *process = qobject_cast<QProcess*>(sender());
    if (process) {
        QString output = process->readAllStandardOutput();

        // 处理输出数据，提取网络名称并添加到列表中
        QStringList lines = output.split("\n");
        for (const QString &line : lines)
        {
            if (line.trimmed().startsWith("SSID"))
            {
                QString networkName = line.split(":").last().trimmed();
                if (!networkName.isEmpty()) {
                    ui->listWidgetWIFI->addItem(networkName);
                }
            }
        }
    }
}

