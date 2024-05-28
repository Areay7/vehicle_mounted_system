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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemoteViewWindow
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *RemoteViewWindow)
    {
        if (RemoteViewWindow->objectName().isEmpty())
            RemoteViewWindow->setObjectName("RemoteViewWindow");
        RemoteViewWindow->resize(1254, 628);
        QFont font;
        font.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        RemoteViewWindow->setFont(font);
        centralwidget = new QWidget(RemoteViewWindow);
        centralwidget->setObjectName("centralwidget");
        RemoteViewWindow->setCentralWidget(centralwidget);

        retranslateUi(RemoteViewWindow);

        QMetaObject::connectSlotsByName(RemoteViewWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RemoteViewWindow)
    {
        RemoteViewWindow->setWindowTitle(QCoreApplication::translate("RemoteViewWindow", "\346\240\221\350\216\223\346\264\276\350\277\234\347\250\213\347\233\221\346\216\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoteViewWindow: public Ui_RemoteViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTEVIEW_H
