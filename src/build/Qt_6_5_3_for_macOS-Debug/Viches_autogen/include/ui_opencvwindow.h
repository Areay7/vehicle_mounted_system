/********************************************************************************
** Form generated from reading UI file 'opencvwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENCVWINDOW_H
#define UI_OPENCVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <registerwin.h>
#include <selectwin.h>

QT_BEGIN_NAMESPACE

class Ui_OpencvWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *showWidget;
    QGridLayout *gridLayout;
    QLabel *picLb;
    RegisterWin *registerWidget;
    SelectWin *selectWidget;

    void setupUi(QMainWindow *OpencvWindow)
    {
        if (OpencvWindow->objectName().isEmpty())
            OpencvWindow->setObjectName("OpencvWindow");
        OpencvWindow->resize(855, 600);
        centralwidget = new QWidget(OpencvWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(-1, -1, 851, 601));
        showWidget = new QWidget();
        showWidget->setObjectName("showWidget");
        gridLayout = new QGridLayout(showWidget);
        gridLayout->setObjectName("gridLayout");
        picLb = new QLabel(showWidget);
        picLb->setObjectName("picLb");
        picLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 166, 249)"));

        gridLayout->addWidget(picLb, 0, 0, 1, 1);

        tabWidget->addTab(showWidget, QString());
        registerWidget = new RegisterWin();
        registerWidget->setObjectName("registerWidget");
        tabWidget->addTab(registerWidget, QString());
        selectWidget = new SelectWin();
        selectWidget->setObjectName("selectWidget");
        tabWidget->addTab(selectWidget, QString());
        OpencvWindow->setCentralWidget(centralwidget);

        retranslateUi(OpencvWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(OpencvWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OpencvWindow)
    {
        OpencvWindow->setWindowTitle(QCoreApplication::translate("OpencvWindow", "MainWindow", nullptr));
        picLb->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(showWidget), QCoreApplication::translate("OpencvWindow", "\350\200\203\345\213\244\345\233\276\345\203\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(registerWidget), QCoreApplication::translate("OpencvWindow", "\346\263\250\345\206\214\347\225\214\351\235\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(selectWidget), QCoreApplication::translate("OpencvWindow", "\346\237\245\350\257\242\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpencvWindow: public Ui_OpencvWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCVWINDOW_H
