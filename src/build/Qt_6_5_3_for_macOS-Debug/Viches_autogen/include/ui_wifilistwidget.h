/********************************************************************************
** Form generated from reading UI file 'wifilistwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIFILISTWIDGET_H
#define UI_WIFILISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wifiListWidget
{
public:
    QListWidget *listWidgetWIFI;
    QLabel *labelWifi;
    QWidget *widgetButton;
    QWidget *widgetKeyboard;

    void setupUi(QWidget *wifiListWidget)
    {
        if (wifiListWidget->objectName().isEmpty())
            wifiListWidget->setObjectName("wifiListWidget");
        wifiListWidget->resize(317, 486);
        wifiListWidget->setStyleSheet(QString::fromUtf8("QWidget#wifiListWidget\n"
"{\n"
"background-color: rgb(73, 92, 105);\n"
"}"));
        listWidgetWIFI = new QListWidget(wifiListWidget);
        listWidgetWIFI->setObjectName("listWidgetWIFI");
        listWidgetWIFI->setGeometry(QRect(0, 40, 321, 201));
        listWidgetWIFI->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        labelWifi = new QLabel(wifiListWidget);
        labelWifi->setObjectName("labelWifi");
        labelWifi->setGeometry(QRect(30, 10, 231, 31));
        labelWifi->setStyleSheet(QString::fromUtf8("color: rgb(239, 41, 41);"));
        widgetButton = new QWidget(wifiListWidget);
        widgetButton->setObjectName("widgetButton");
        widgetButton->setGeometry(QRect(0, 230, 301, 51));
        widgetKeyboard = new QWidget(wifiListWidget);
        widgetKeyboard->setObjectName("widgetKeyboard");
        widgetKeyboard->setGeometry(QRect(10, 280, 301, 191));
        widgetKeyboard->setStyleSheet(QString::fromUtf8(" \n"
"background-color: rgb(255, 255, 255);"));

        retranslateUi(wifiListWidget);

        QMetaObject::connectSlotsByName(wifiListWidget);
    } // setupUi

    void retranslateUi(QWidget *wifiListWidget)
    {
        wifiListWidget->setWindowTitle(QCoreApplication::translate("wifiListWidget", "Form", nullptr));
        labelWifi->setText(QCoreApplication::translate("wifiListWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wifiListWidget: public Ui_wifiListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIFILISTWIDGET_H
