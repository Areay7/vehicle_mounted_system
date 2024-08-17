/********************************************************************************
** Form generated from reading UI file 'remoteview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTEVIEW_H
#define UI_REMOTEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_RemoteView
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textbrowser_response;
    QPushButton *btn_request;
    QPlainTextEdit *plaintextedit_response;
    QPushButton *btn_return;
    QLabel *label;

    void setupUi(QDialog *RemoteView)
    {
        if (RemoteView->objectName().isEmpty())
            RemoteView->setObjectName("RemoteView");
        RemoteView->resize(1215, 647);
        gridLayout = new QGridLayout(RemoteView);
        gridLayout->setObjectName("gridLayout");
        textbrowser_response = new QTextBrowser(RemoteView);
        textbrowser_response->setObjectName("textbrowser_response");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textbrowser_response->sizePolicy().hasHeightForWidth());
        textbrowser_response->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        textbrowser_response->setFont(font);
        textbrowser_response->setOpenLinks(false);

        gridLayout->addWidget(textbrowser_response, 1, 0, 1, 3);

        btn_request = new QPushButton(RemoteView);
        btn_request->setObjectName("btn_request");
        btn_request->setMinimumSize(QSize(0, 40));
        btn_request->setMaximumSize(QSize(60, 35));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(20);
        font1.setBold(true);
        btn_request->setFont(font1);
        btn_request->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/remoteRes/home_select.png);\n"
"background-color: rgba(0,0,0,0);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/remoteRes/home_common.png);\n"
"background-color: rgba(0,0,0,0);\n"
"border: none;\n"
"}\n"
""));

        gridLayout->addWidget(btn_request, 0, 0, 1, 1);

        plaintextedit_response = new QPlainTextEdit(RemoteView);
        plaintextedit_response->setObjectName("plaintextedit_response");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plaintextedit_response->sizePolicy().hasHeightForWidth());
        plaintextedit_response->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(plaintextedit_response, 1, 3, 1, 1);

        btn_return = new QPushButton(RemoteView);
        btn_return->setObjectName("btn_return");
        btn_return->setMinimumSize(QSize(0, 42));
        btn_return->setMaximumSize(QSize(50, 35));
        btn_return->setFont(font1);
        btn_return->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/remoteRes/return_select.png);\n"
"background-color: rgba(0,0,0,0);\n"
"border: none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/remoteRes/return_common.png);\n"
"background-color: rgba(0,0,0,0);\n"
"border: none;\n"
"}\n"
""));

        gridLayout->addWidget(btn_return, 0, 1, 1, 1);

        label = new QLabel(RemoteView);
        label->setObjectName("label");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(22);
        label->setFont(font2);

        gridLayout->addWidget(label, 0, 2, 1, 2);


        retranslateUi(RemoteView);

        QMetaObject::connectSlotsByName(RemoteView);
    } // setupUi

    void retranslateUi(QDialog *RemoteView)
    {
        RemoteView->setWindowTitle(QCoreApplication::translate("RemoteView", "Dialog", nullptr));
        btn_request->setText(QString());
        btn_return->setText(QString());
        label->setText(QCoreApplication::translate("RemoteView", " Tip :  Ringht Click to View  or Downloads", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoteView: public Ui_RemoteView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTEVIEW_H
