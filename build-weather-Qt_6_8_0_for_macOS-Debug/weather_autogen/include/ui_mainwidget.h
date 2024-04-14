/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *btnOpenWeatherWindow;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(885, 554);
        btnOpenWeatherWindow = new QPushButton(Form);
        btnOpenWeatherWindow->setObjectName("btnOpenWeatherWindow");
        btnOpenWeatherWindow->setGeometry(QRect(690, 110, 100, 32));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(690, 200, 100, 32));
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(690, 280, 100, 32));
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(690, 360, 100, 32));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        btnOpenWeatherWindow->setText(QCoreApplication::translate("Form", "\345\244\251\346\260\224", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "\347\212\266\346\200\201", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
