/********************************************************************************
** Form generated from reading UI file 'remotecontrol.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTECONTROL_H
#define UI_REMOTECONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemoteWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonGoHead;
    QPushButton *pushButtonTurnLeft;
    QPushButton *pushButtonGoBack;
    QPushButton *pushButtonTurnRight;
    QPushButton *pushButtonLink;
    QLabel *labelIpText;
    QLabel *labelPortText;
    QTextEdit *textEditInfomation;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditLinkIp;
    QLineEdit *lineEditLinkPort;
    QPushButton *pushButtonStop;

    void setupUi(QMainWindow *RemoteWindow)
    {
        if (RemoteWindow->objectName().isEmpty())
            RemoteWindow->setObjectName("RemoteWindow");
        RemoteWindow->resize(1202, 628);
        QFont font;
        font.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        RemoteWindow->setFont(font);
        centralwidget = new QWidget(RemoteWindow);
        centralwidget->setObjectName("centralwidget");
        pushButtonGoHead = new QPushButton(centralwidget);
        pushButtonGoHead->setObjectName("pushButtonGoHead");
        pushButtonGoHead->setGeometry(QRect(940, 170, 101, 61));
        pushButtonGoHead->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/remoteRes/shang.png);\n"
"background: rgba(0,0,0,0%);"));
        pushButtonTurnLeft = new QPushButton(centralwidget);
        pushButtonTurnLeft->setObjectName("pushButtonTurnLeft");
        pushButtonTurnLeft->setGeometry(QRect(850, 240, 91, 51));
        pushButtonTurnLeft->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/remoteRes/zuo.png);\n"
"background: rgba(0,0,0,0%);"));
        pushButtonGoBack = new QPushButton(centralwidget);
        pushButtonGoBack->setObjectName("pushButtonGoBack");
        pushButtonGoBack->setGeometry(QRect(940, 300, 101, 51));
        pushButtonGoBack->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/remoteRes/xia.png);\n"
"background: rgba(0,0,0,0%);"));
        pushButtonTurnRight = new QPushButton(centralwidget);
        pushButtonTurnRight->setObjectName("pushButtonTurnRight");
        pushButtonTurnRight->setGeometry(QRect(1040, 240, 101, 51));
        pushButtonTurnRight->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/remoteRes/you.png);\n"
"background: rgba(0,0,0,0%);"));
        pushButtonLink = new QPushButton(centralwidget);
        pushButtonLink->setObjectName("pushButtonLink");
        pushButtonLink->setGeometry(QRect(950, 520, 81, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(18);
        pushButtonLink->setFont(font1);
        pushButtonLink->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/remoteRes/true.png);\n"
"background: rgba(0,0,0,0%);"));
        labelIpText = new QLabel(centralwidget);
        labelIpText->setObjectName("labelIpText");
        labelIpText->setGeometry(QRect(850, 380, 61, 51));
        labelIpText->setFont(font1);
        labelIpText->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/remoteRes/IP.png);\n"
"background: rgba(0,0,0,0%);"));
        labelPortText = new QLabel(centralwidget);
        labelPortText->setObjectName("labelPortText");
        labelPortText->setGeometry(QRect(860, 440, 51, 41));
        labelPortText->setFont(font1);
        labelPortText->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/remoteRes/port.png);\n"
"background: rgba(0,0,0,0%);"));
        textEditInfomation = new QTextEdit(centralwidget);
        textEditInfomation->setObjectName("textEditInfomation");
        textEditInfomation->setGeometry(QRect(840, 40, 331, 111));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(910, 380, 161, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditLinkIp = new QLineEdit(layoutWidget);
        lineEditLinkIp->setObjectName("lineEditLinkIp");
        lineEditLinkIp->setFont(font1);

        verticalLayout->addWidget(lineEditLinkIp);

        lineEditLinkPort = new QLineEdit(layoutWidget);
        lineEditLinkPort->setObjectName("lineEditLinkPort");
        lineEditLinkPort->setFont(font1);

        verticalLayout->addWidget(lineEditLinkPort);

        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName("pushButtonStop");
        pushButtonStop->setGeometry(QRect(940, 230, 101, 71));
        pushButtonStop->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/remoteRes/stop.png);\n"
"background: rgba(0,0,0,0%);"));
        RemoteWindow->setCentralWidget(centralwidget);

        retranslateUi(RemoteWindow);

        QMetaObject::connectSlotsByName(RemoteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RemoteWindow)
    {
        RemoteWindow->setWindowTitle(QCoreApplication::translate("RemoteWindow", "\350\277\234\347\250\213\346\216\247\345\210\266\347\273\210\347\253\257", nullptr));
        pushButtonGoHead->setText(QString());
        pushButtonTurnLeft->setText(QString());
        pushButtonGoBack->setText(QString());
        pushButtonTurnRight->setText(QString());
        pushButtonLink->setText(QString());
        labelIpText->setText(QString());
        labelPortText->setText(QString());
        lineEditLinkIp->setText(QCoreApplication::translate("RemoteWindow", "nps.areay7.cn", nullptr));
        lineEditLinkPort->setText(QCoreApplication::translate("RemoteWindow", "8098", nullptr));
        pushButtonStop->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RemoteWindow: public Ui_RemoteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTECONTROL_H
