/********************************************************************************
** Form generated from reading UI file 'currentsituation.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTSITUATION_H
#define UI_CURRENTSITUATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QCommandLinkButton *btn_Publish;
    QCommandLinkButton *btn_Subcribe;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_QoSTitle;
    QLabel *label_QoS;
    QLabel *label_subscribr_status;
    QHBoxLayout *horizontalLayout;
    QLabel *label_MqttStateTitle;
    QLabel *label_MqttState;
    QVBoxLayout *verticalLayout;
    QLabel *label_payload;
    QLineEdit *line_pubtopic;
    QLineEdit *line_payload;
    QLabel *label_topic;
    QLineEdit *line_subtopic;
    QMenuBar *menubar;
    QMenu *menuHello;
    QMenu *menuMqtt;
    QMenu *menuSet;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(623, 484);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        btn_Publish = new QCommandLinkButton(centralwidget);
        btn_Publish->setObjectName("btn_Publish");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_Publish->sizePolicy().hasHeightForWidth());
        btn_Publish->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btn_Publish);

        btn_Subcribe = new QCommandLinkButton(centralwidget);
        btn_Subcribe->setObjectName("btn_Subcribe");
        sizePolicy.setHeightForWidth(btn_Subcribe->sizePolicy().hasHeightForWidth());
        btn_Subcribe->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btn_Subcribe);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_QoSTitle = new QLabel(centralwidget);
        label_QoSTitle->setObjectName("label_QoSTitle");

        horizontalLayout_2->addWidget(label_QoSTitle);

        label_QoS = new QLabel(centralwidget);
        label_QoS->setObjectName("label_QoS");

        horizontalLayout_2->addWidget(label_QoS);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_subscribr_status = new QLabel(centralwidget);
        label_subscribr_status->setObjectName("label_subscribr_status");

        verticalLayout_2->addWidget(label_subscribr_status);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_MqttStateTitle = new QLabel(centralwidget);
        label_MqttStateTitle->setObjectName("label_MqttStateTitle");

        horizontalLayout->addWidget(label_MqttStateTitle);

        label_MqttState = new QLabel(centralwidget);
        label_MqttState->setObjectName("label_MqttState");

        horizontalLayout->addWidget(label_MqttState);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_payload = new QLabel(centralwidget);
        label_payload->setObjectName("label_payload");
        label_payload->setMinimumSize(QSize(0, 25));

        verticalLayout->addWidget(label_payload);

        line_pubtopic = new QLineEdit(centralwidget);
        line_pubtopic->setObjectName("line_pubtopic");
        line_pubtopic->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(line_pubtopic);

        line_payload = new QLineEdit(centralwidget);
        line_payload->setObjectName("line_payload");
        line_payload->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(line_payload);

        label_topic = new QLabel(centralwidget);
        label_topic->setObjectName("label_topic");
        label_topic->setMinimumSize(QSize(0, 25));

        verticalLayout->addWidget(label_topic);

        line_subtopic = new QLineEdit(centralwidget);
        line_subtopic->setObjectName("line_subtopic");
        line_subtopic->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(line_subtopic);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 623, 37));
        menuHello = new QMenu(menubar);
        menuHello->setObjectName("menuHello");
        menuMqtt = new QMenu(menubar);
        menuMqtt->setObjectName("menuMqtt");
        menuSet = new QMenu(menubar);
        menuSet->setObjectName("menuSet");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHello->menuAction());
        menubar->addAction(menuMqtt->menuAction());
        menubar->addAction(menuSet->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_Publish->setText(QCoreApplication::translate("MainWindow", "Publish", nullptr));
        btn_Subcribe->setText(QCoreApplication::translate("MainWindow", "Subcribe", nullptr));
        label_QoSTitle->setText(QCoreApplication::translate("MainWindow", "QoS", nullptr));
        label_QoS->setText(QCoreApplication::translate("MainWindow", "QoS Value", nullptr));
        label_subscribr_status->setText(QCoreApplication::translate("MainWindow", "Subcribe Status", nullptr));
        label_MqttStateTitle->setText(QCoreApplication::translate("MainWindow", "MqttState:", nullptr));
        label_MqttState->setText(QCoreApplication::translate("MainWindow", "MqttState", nullptr));
        label_payload->setText(QCoreApplication::translate("MainWindow", "Payload", nullptr));
        label_topic->setText(QCoreApplication::translate("MainWindow", "Topic", nullptr));
        menuHello->setTitle(QCoreApplication::translate("MainWindow", "Hello", nullptr));
        menuMqtt->setTitle(QCoreApplication::translate("MainWindow", "Mqtt", nullptr));
        menuSet->setTitle(QCoreApplication::translate("MainWindow", "Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTSITUATION_H
