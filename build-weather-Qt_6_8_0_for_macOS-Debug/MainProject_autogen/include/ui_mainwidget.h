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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *btnOpenWeatherWindow;
    QPushButton *btnOpenSituationWindow;
    QPushButton *btnOpenControlWindow;
    QPushButton *pushButton_4;
    QLabel *label;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(885, 554);
        btnOpenWeatherWindow = new QPushButton(Form);
        btnOpenWeatherWindow->setObjectName("btnOpenWeatherWindow");
        btnOpenWeatherWindow->setGeometry(QRect(730, 110, 100, 32));
        btnOpenSituationWindow = new QPushButton(Form);
        btnOpenSituationWindow->setObjectName("btnOpenSituationWindow");
        btnOpenSituationWindow->setGeometry(QRect(730, 200, 100, 32));
        btnOpenControlWindow = new QPushButton(Form);
        btnOpenControlWindow->setObjectName("btnOpenControlWindow");
        btnOpenControlWindow->setGeometry(QRect(730, 280, 100, 32));
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(730, 360, 100, 32));
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 80, 671, 371));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "XIAOMI-SU7\350\275\246\350\275\275\347\263\273\347\273\237", nullptr));
        btnOpenWeatherWindow->setText(QCoreApplication::translate("Form", "\345\244\251\346\260\224", nullptr));
        btnOpenSituationWindow->setText(QCoreApplication::translate("Form", "\347\212\266\346\200\201", nullptr));
        btnOpenControlWindow->setText(QCoreApplication::translate("Form", "\346\216\247\345\210\266", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
