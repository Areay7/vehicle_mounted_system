/********************************************************************************
** Form generated from reading UI file 'controlwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWIDGET_H
#define UI_CONTROLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlWidget
{
public:
    QFrame *frame;
    QWidget *widgetHumidity;
    QLabel *labHumText;
    QLabel *labHumIcon;
    QLabel *labSetHumidity;
    QPushButton *pushButtonHumSw;
    QPushButton *pushButtonSetHumAdd;
    QPushButton *pushButtonSetHumSub;
    QWidget *widgetLED;
    QLabel *labLEDText;
    QPushButton *pushButtonSetLED;
    QWidget *widgetTemper;
    QLabel *labMode;
    QLabel *labSettemperIcon;
    QLabel *labSetTemperText;
    QPushButton *pushButtonSetMode;
    QPushButton *pushButtonTemperSw;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonSub;
    QWidget *widgetDoor;
    QLabel *labelDoorText;
    QPushButton *pushButtonSetDoor;
    QWidget *widgetBLUE;
    QLabel *labBULEText;
    QPushButton *pushButtonSetBlue;
    QWidget *widgetAlarm;
    QLabel *labAlarmTitle;
    QLabel *labAlarmICON;
    QLabel *labHOTData;
    QLabel *labHOTIcon;
    QLabel *labHOT;
    QLabel *labDRY;
    QLabel *labTempIcon;
    QLabel *labDRYData;
    QLabel *labOPENIcon;
    QLabel *labOPENData;
    QLabel *labOPEN;
    QLabel *labTempTip;
    QLabel *labHumTip;
    QWidget *widgetWIFI;
    QLabel *labWIFIText;
    QPushButton *pushButtonSetWIFI;
    QStackedWidget *stackedWidgetSetting;
    QWidget *pageVoice;
    QLabel *label_27;
    QLabel *label_28;
    QPushButton *pushButtonEdit;
    QTextEdit *textEdit;
    QWidget *pageWIFI;
    QFrame *verticalLayout;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QFrame *line_2;
    QWidget *widgetVoice;
    QPushButton *pushButtonVoice;

    void setupUi(QWidget *ControlWidget)
    {
        if (ControlWidget->objectName().isEmpty())
            ControlWidget->setObjectName("ControlWidget");
        ControlWidget->resize(999, 542);
        ControlWidget->setStyleSheet(QString::fromUtf8("QFrame#frame\n"
"{\n"
"background-color: rgb(234, 243, 244);\n"
"}\n"
""));
        frame = new QFrame(ControlWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, -10, 1001, 551));
        frame->setStyleSheet(QString::fromUtf8("\n"
"QWidget#widgetVoice\n"
"{\n"
"border-image: url(:/image/recordVoiceBack.png);\n"
"border-top-right-radius: 30px; \n"
"border-top-left-radius: 30px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widgetHumidity = new QWidget(frame);
        widgetHumidity->setObjectName("widgetHumidity");
        widgetHumidity->setGeometry(QRect(20, 410, 301, 121));
        widgetHumidity->setStyleSheet(QString::fromUtf8("QWidget#widgetHumidity\n"
"{\n"
"background-color: rgb(242, 248, 248);\n"
"border-radius: 15px; \n"
"}"));
        labHumText = new QLabel(widgetHumidity);
        labHumText->setObjectName("labHumText");
        labHumText->setGeometry(QRect(10, 10, 141, 31));
        QFont font;
        font.setPointSize(15);
        labHumText->setFont(font);
        labHumText->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:#4aa2a7"));
        labHumIcon = new QLabel(widgetHumidity);
        labHumIcon->setObjectName("labHumIcon");
        labHumIcon->setGeometry(QRect(10, 50, 41, 61));
        labHumIcon->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 243, 244);\n"
"border-top-left-radius: 10px; \n"
"border-bottom-left-radius: 10px;\n"
"image: url(:/image/HumIcon.png);"));
        labSetHumidity = new QLabel(widgetHumidity);
        labSetHumidity->setObjectName("labSetHumidity");
        labSetHumidity->setGeometry(QRect(50, 50, 81, 61));
        labSetHumidity->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 243, 244);\n"
"border-top-right-radius: 10px; \n"
"border-bottom-right-radius: 10px;\n"
"color:#1485fb;"));
        pushButtonHumSw = new QPushButton(widgetHumidity);
        pushButtonHumSw->setObjectName("pushButtonHumSw");
        pushButtonHumSw->setGeometry(QRect(230, 10, 61, 31));
        pushButtonHumSw->setStyleSheet(QString::fromUtf8("border-radius: 12px; \n"
"border-image: url(:/image/TemperSwitchOFF.png);"));
        pushButtonSetHumAdd = new QPushButton(widgetHumidity);
        pushButtonSetHumAdd->setObjectName("pushButtonSetHumAdd");
        pushButtonSetHumAdd->setGeometry(QRect(150, 50, 61, 61));
        pushButtonSetHumAdd->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"background: rgba(0,0,0,0%);\n"
"border-image: url(:/image/TempPressAdd.png);"));
        pushButtonSetHumSub = new QPushButton(widgetHumidity);
        pushButtonSetHumSub->setObjectName("pushButtonSetHumSub");
        pushButtonSetHumSub->setGeometry(QRect(230, 50, 61, 61));
        pushButtonSetHumSub->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"border-image: url(:/image/TempPressSub.png);\n"
"background: rgba(0,0,0,0%);"));
        widgetLED = new QWidget(frame);
        widgetLED->setObjectName("widgetLED");
        widgetLED->setGeometry(QRect(20, 120, 141, 131));
        widgetLED->setStyleSheet(QString::fromUtf8("QWidget#widgetLED\n"
"{\n"
"background-color: rgb(242, 248, 248);\n"
"border-radius: 15px; \n"
"}"));
        labLEDText = new QLabel(widgetLED);
        labLEDText->setObjectName("labLEDText");
        labLEDText->setGeometry(QRect(10, 10, 61, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(false);
        labLEDText->setFont(font1);
        labLEDText->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:#4aa2a7"));
        pushButtonSetLED = new QPushButton(widgetLED);
        pushButtonSetLED->setObjectName("pushButtonSetLED");
        pushButtonSetLED->setGeometry(QRect(20, 60, 91, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(14);
        pushButtonSetLED->setFont(font2);
        pushButtonSetLED->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/image/LEDSwitchOFF.png);\n"
"background: rgba(0,0,0,0%);"));
        widgetTemper = new QWidget(frame);
        widgetTemper->setObjectName("widgetTemper");
        widgetTemper->setGeometry(QRect(20, 270, 301, 121));
        widgetTemper->setStyleSheet(QString::fromUtf8("\n"
"QWidget#widgetTemper\n"
"{\n"
"background-color: rgb(242, 248, 248);\n"
"border-radius: 15px; \n"
"}"));
        labMode = new QLabel(widgetTemper);
        labMode->setObjectName("labMode");
        labMode->setGeometry(QRect(10, 10, 58, 16));
        labMode->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:#4aa2a7"));
        labSettemperIcon = new QLabel(widgetTemper);
        labSettemperIcon->setObjectName("labSettemperIcon");
        labSettemperIcon->setGeometry(QRect(10, 50, 41, 61));
        labSettemperIcon->setStyleSheet(QString::fromUtf8("image: url(:/image/Tempcon.png);\n"
"background-color: rgb(234, 243, 244);\n"
"border-top-left-radius: 10px; \n"
"border-bottom-left-radius: 10px;"));
        labSetTemperText = new QLabel(widgetTemper);
        labSetTemperText->setObjectName("labSetTemperText");
        labSetTemperText->setGeometry(QRect(50, 50, 81, 61));
        labSetTemperText->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 243, 244);\n"
"border-top-right-radius: 10px; \n"
"border-bottom-right-radius: 10px;\n"
"color:#1485fb;"));
        pushButtonSetMode = new QPushButton(widgetTemper);
        pushButtonSetMode->setObjectName("pushButtonSetMode");
        pushButtonSetMode->setGeometry(QRect(150, 10, 61, 31));
        pushButtonSetMode->setStyleSheet(QString::fromUtf8("border-radius: 5px; \n"
"border-image: url(:/image/cold.png);"));
        pushButtonTemperSw = new QPushButton(widgetTemper);
        pushButtonTemperSw->setObjectName("pushButtonTemperSw");
        pushButtonTemperSw->setGeometry(QRect(230, 10, 61, 31));
        pushButtonTemperSw->setStyleSheet(QString::fromUtf8("border-radius: 12px; \n"
"border-image: url(:/image/TemperSwitchOFF.png);"));
        pushButtonAdd = new QPushButton(widgetTemper);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(150, 50, 61, 61));
        pushButtonAdd->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"background: rgba(0,0,0,0%);\n"
"border-image: url(:/image/TempSwitchAdd.png);"));
        pushButtonSub = new QPushButton(widgetTemper);
        pushButtonSub->setObjectName("pushButtonSub");
        pushButtonSub->setGeometry(QRect(230, 50, 61, 61));
        pushButtonSub->setStyleSheet(QString::fromUtf8("border-radius: 10px; \n"
"border-image: url(:/image/TempSwitchSub.png);\n"
"background: rgba(0,0,0,0%);"));
        widgetDoor = new QWidget(frame);
        widgetDoor->setObjectName("widgetDoor");
        widgetDoor->setGeometry(QRect(180, 120, 141, 131));
        widgetDoor->setStyleSheet(QString::fromUtf8("QWidget#widgetDoor\n"
"{\n"
"background-color: rgb(242, 248, 248);\n"
"border-radius: 15px; \n"
"}"));
        labelDoorText = new QLabel(widgetDoor);
        labelDoorText->setObjectName("labelDoorText");
        labelDoorText->setGeometry(QRect(10, 10, 61, 21));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        labelDoorText->setFont(font3);
        labelDoorText->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:#4aa2a7"));
        pushButtonSetDoor = new QPushButton(widgetDoor);
        pushButtonSetDoor->setObjectName("pushButtonSetDoor");
        pushButtonSetDoor->setGeometry(QRect(20, 60, 91, 41));
        pushButtonSetDoor->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"background: rgba(0,0,0,0%);\n"
"border-image: url(:/image/DoorSwitchOFF.png);\n"
""));
        widgetBLUE = new QWidget(frame);
        widgetBLUE->setObjectName("widgetBLUE");
        widgetBLUE->setGeometry(QRect(530, 120, 161, 131));
        widgetBLUE->setStyleSheet(QString::fromUtf8("QWidget#widgetBLUE\n"
"{\n"
"background-color: rgb(242, 248, 248);\n"
"border-radius: 15px; \n"
"}"));
        labBULEText = new QLabel(widgetBLUE);
        labBULEText->setObjectName("labBULEText");
        labBULEText->setGeometry(QRect(10, 10, 81, 21));
        labBULEText->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:#1177b0"));
        pushButtonSetBlue = new QPushButton(widgetBLUE);
        pushButtonSetBlue->setObjectName("pushButtonSetBlue");
        pushButtonSetBlue->setGeometry(QRect(30, 60, 91, 41));
        pushButtonSetBlue->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/image/BlueSwitchOFF.png);\n"
"background: rgba(0,0,0,0%);"));
        widgetAlarm = new QWidget(frame);
        widgetAlarm->setObjectName("widgetAlarm");
        widgetAlarm->setGeometry(QRect(360, 260, 331, 270));
        widgetAlarm->setStyleSheet(QString::fromUtf8("\n"
"QWidget#widgetAlarm\n"
"{\n"
"background-color: rgb(242, 248, 248);\n"
"border-radius: 18px; \n"
"}"));
        labAlarmTitle = new QLabel(widgetAlarm);
        labAlarmTitle->setObjectName("labAlarmTitle");
        labAlarmTitle->setGeometry(QRect(20, 20, 141, 31));
        labAlarmTitle->setFont(font);
        labAlarmTitle->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:#4aa2a7"));
        labAlarmICON = new QLabel(widgetAlarm);
        labAlarmICON->setObjectName("labAlarmICON");
        labAlarmICON->setGeometry(QRect(100, 60, 161, 131));
        labAlarmICON->setStyleSheet(QString::fromUtf8("border-image: url(:/image/alarm.png);\n"
"background: rgba(0,0,0,0%);"));
        labHOTData = new QLabel(widgetAlarm);
        labHOTData->setObjectName("labHOTData");
        labHOTData->setGeometry(QRect(50, 200, 51, 31));
        labHOTData->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-top-right-radius: 5px; \n"
"border-top-left-radius: 5px;\n"
"color:#f47780;"));
        labHOTIcon = new QLabel(widgetAlarm);
        labHOTIcon->setObjectName("labHOTIcon");
        labHOTIcon->setGeometry(QRect(20, 200, 21, 31));
        labHOTIcon->setStyleSheet(QString::fromUtf8("border-top-right-radius: 5px; \n"
"border-top-left-radius: 5px;\n"
"image: url(:/image/alarmTemp.png);"));
        labHOT = new QLabel(widgetAlarm);
        labHOT->setObjectName("labHOT");
        labHOT->setGeometry(QRect(30, 230, 71, 20));
        labHOT->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(244, 119, 128);\n"
"color:white;\n"
"border-bottom-right-radius: 5px; \n"
"border-bottom-left-radius: 5px;"));
        labDRY = new QLabel(widgetAlarm);
        labDRY->setObjectName("labDRY");
        labDRY->setGeometry(QRect(120, 230, 71, 20));
        labDRY->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(119, 131, 244);\n"
"color:white;\n"
"border-bottom-right-radius: 5px; \n"
"border-bottom-left-radius: 5px;"));
        labTempIcon = new QLabel(widgetAlarm);
        labTempIcon->setObjectName("labTempIcon");
        labTempIcon->setGeometry(QRect(113, 200, 21, 31));
        labTempIcon->setStyleSheet(QString::fromUtf8("image: url(:/image/alarmDry.png);\n"
"border-top-right-radius: 5px; \n"
"border-top-left-radius: 5px;"));
        labDRYData = new QLabel(widgetAlarm);
        labDRYData->setObjectName("labDRYData");
        labDRYData->setGeometry(QRect(140, 200, 51, 31));
        labDRYData->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-top-right-radius: 5px; \n"
"border-top-left-radius: 5px;\n"
"color:#7783f4;"));
        labOPENIcon = new QLabel(widgetAlarm);
        labOPENIcon->setObjectName("labOPENIcon");
        labOPENIcon->setGeometry(QRect(210, 200, 21, 31));
        labOPENIcon->setStyleSheet(QString::fromUtf8("image: url(:/image/alarmOpen.png);\n"
"border-top-right-radius: 5px; \n"
"border-top-left-radius: 5px;"));
        labOPENData = new QLabel(widgetAlarm);
        labOPENData->setObjectName("labOPENData");
        labOPENData->setGeometry(QRect(240, 200, 51, 31));
        labOPENData->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-top-right-radius: 5px; \n"
"border-top-left-radius: 5px;\n"
"color:#f18040"));
        labOPEN = new QLabel(widgetAlarm);
        labOPEN->setObjectName("labOPEN");
        labOPEN->setGeometry(QRect(220, 230, 71, 20));
        labOPEN->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(241, 128, 64);\n"
"color:white;\n"
"border-bottom-right-radius: 5px; \n"
"border-bottom-left-radius: 5px;"));
        labTempTip = new QLabel(widgetAlarm);
        labTempTip->setObjectName("labTempTip");
        labTempTip->setGeometry(QRect(140, 40, 71, 41));
        labTempTip->setStyleSheet(QString::fromUtf8("border-image: url(:/image/alarmTemperTooltip.png);\n"
"background: rgba(0,0,0,0%);"));
        labHumTip = new QLabel(widgetAlarm);
        labHumTip->setObjectName("labHumTip");
        labHumTip->setGeometry(QRect(230, 150, 61, 31));
        labHumTip->setStyleSheet(QString::fromUtf8("border-image: url(:/image/alarmHumTooltip.png);\n"
"background: rgba(0,0,0,0%);"));
        widgetWIFI = new QWidget(frame);
        widgetWIFI->setObjectName("widgetWIFI");
        widgetWIFI->setGeometry(QRect(360, 120, 151, 131));
        widgetWIFI->setStyleSheet(QString::fromUtf8("QWidget#widgetWIFI\n"
"{\n"
"background-color: rgb(242, 248, 248);\n"
"border-radius: 15px; \n"
"}"));
        labWIFIText = new QLabel(widgetWIFI);
        labWIFIText->setObjectName("labWIFIText");
        labWIFIText->setGeometry(QRect(10, 10, 61, 21));
        labWIFIText->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:#ec2c64"));
        pushButtonSetWIFI = new QPushButton(widgetWIFI);
        pushButtonSetWIFI->setObjectName("pushButtonSetWIFI");
        pushButtonSetWIFI->setGeometry(QRect(30, 60, 91, 41));
        pushButtonSetWIFI->setStyleSheet(QString::fromUtf8("border-radius:28px; \n"
"border-image: url(:/image/WIFISwitchOFF.png);\n"
"background: rgba(0,0,0,0%);"));
        stackedWidgetSetting = new QStackedWidget(frame);
        stackedWidgetSetting->setObjectName("stackedWidgetSetting");
        stackedWidgetSetting->setGeometry(QRect(740, 10, 241, 471));
        stackedWidgetSetting->setStyleSheet(QString::fromUtf8("border-radius: 30px; "));
        pageVoice = new QWidget();
        pageVoice->setObjectName("pageVoice");
        label_27 = new QLabel(pageVoice);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(20, 50, 201, 111));
        label_27->setStyleSheet(QString::fromUtf8("border-image: url(:/image/voiceback.png);\n"
"background: rgba(0,0,0,0%);"));
        label_28 = new QLabel(pageVoice);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(67, 195, 151, 31));
        QFont font4;
        font4.setPointSize(15);
        font4.setKerning(true);
        label_28->setFont(font4);
        label_28->setStyleSheet(QString::fromUtf8("color:#4aa2a7;\n"
"background-color: rgb(73, 92, 105);"));
        label_28->setScaledContents(false);
        label_28->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButtonEdit = new QPushButton(pageVoice);
        pushButtonEdit->setObjectName("pushButtonEdit");
        pushButtonEdit->setGeometry(QRect(20, 200, 31, 31));
        pushButtonEdit->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"border-image: url(:/image/edotLean.png);"));
        textEdit = new QTextEdit(pageVoice);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 240, 231, 231));
        textEdit->setStyleSheet(QString::fromUtf8("color:#EAF3F4;\n"
"background-color: rgb(29, 43, 50);"));
        stackedWidgetSetting->addWidget(pageVoice);
        pageWIFI = new QWidget();
        pageWIFI->setObjectName("pageWIFI");
        stackedWidgetSetting->addWidget(pageWIFI);
        verticalLayout = new QFrame(frame);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setGeometry(QRect(0, 0, 721, 111));
        verticalLayout->setFrameShape(QFrame::StyledPanel);
        verticalLayout->setFrameShadow(QFrame::Raised);
        line = new QFrame(verticalLayout);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 90, 711, 41));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(verticalLayout);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 20, 231, 31));
        QFont font5;
        font5.setPointSize(17);
        label->setFont(font5);
        label->setStyleSheet(QString::fromUtf8("color:#4aa2a7"));
        label_2 = new QLabel(verticalLayout);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 60, 206, 20));
        label_2->setFont(font5);
        label_2->setStyleSheet(QString::fromUtf8("color:#4aa2a7"));
        line_2 = new QFrame(frame);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(710, 0, 20, 571));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widgetVoice = new QWidget(frame);
        widgetVoice->setObjectName("widgetVoice");
        widgetVoice->setGeometry(QRect(750, 490, 221, 61));
        pushButtonVoice = new QPushButton(widgetVoice);
        pushButtonVoice->setObjectName("pushButtonVoice");
        pushButtonVoice->setGeometry(QRect(10, 10, 211, 41));
        pushButtonVoice->setStyleSheet(QString::fromUtf8("border-radius: 21px; \n"
"border-image: url(:/image/recordVoiceBackRelace.png);\n"
"background: rgba(0,0,0,0%);"));

        retranslateUi(ControlWidget);

        stackedWidgetSetting->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ControlWidget);
    } // setupUi

    void retranslateUi(QWidget *ControlWidget)
    {
        ControlWidget->setWindowTitle(QCoreApplication::translate("ControlWidget", "\346\216\247\345\210\266\347\225\214\351\235\242", nullptr));
        labHumText->setText(QCoreApplication::translate("ControlWidget", "DEHUMDIFIER", nullptr));
        labHumIcon->setText(QString());
        labSetHumidity->setText(QCoreApplication::translate("ControlWidget", "   25.55%", nullptr));
        pushButtonHumSw->setText(QString());
        pushButtonSetHumAdd->setText(QString());
        pushButtonSetHumSub->setText(QString());
        labLEDText->setText(QCoreApplication::translate("ControlWidget", "LIGHT", nullptr));
        pushButtonSetLED->setText(QString());
        labMode->setText(QCoreApplication::translate("ControlWidget", "COLD", nullptr));
        labSettemperIcon->setText(QString());
        labSetTemperText->setText(QCoreApplication::translate("ControlWidget", "   25.55\302\260C", nullptr));
        pushButtonSetMode->setText(QString());
        pushButtonTemperSw->setText(QString());
        pushButtonAdd->setText(QString());
        pushButtonSub->setText(QString());
        labelDoorText->setText(QCoreApplication::translate("ControlWidget", "Door", nullptr));
        pushButtonSetDoor->setText(QString());
        labBULEText->setText(QCoreApplication::translate("ControlWidget", "BLUETOOTH", nullptr));
        pushButtonSetBlue->setText(QString());
        labAlarmTitle->setText(QCoreApplication::translate("ControlWidget", "EARLY WARNING", nullptr));
        labAlarmICON->setText(QString());
        labHOTData->setText(QCoreApplication::translate("ControlWidget", "   45\302\260C", nullptr));
        labHOTIcon->setText(QString());
        labHOT->setText(QCoreApplication::translate("ControlWidget", "      HOT", nullptr));
        labDRY->setText(QCoreApplication::translate("ControlWidget", "       DRY", nullptr));
        labTempIcon->setText(QString());
        labDRYData->setText(QCoreApplication::translate("ControlWidget", "    10%", nullptr));
        labOPENIcon->setText(QString());
        labOPENData->setText(QCoreApplication::translate("ControlWidget", "     ON", nullptr));
        labOPEN->setText(QCoreApplication::translate("ControlWidget", "      OPEN", nullptr));
        labTempTip->setText(QString());
        labHumTip->setText(QString());
        labWIFIText->setText(QCoreApplication::translate("ControlWidget", "WIFI", nullptr));
        pushButtonSetWIFI->setText(QString());
        label_27->setText(QString());
#if QT_CONFIG(tooltip)
        label_28->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_28->setText(QCoreApplication::translate("ControlWidget", "   Speech - To - Text", nullptr));
        pushButtonEdit->setText(QString());
        label->setText(QCoreApplication::translate("ControlWidget", "                   \345\260\217 \347\261\263  S  U  7", nullptr));
        label_2->setText(QCoreApplication::translate("ControlWidget", "          \346\231\272   \350\203\275   \350\275\246   \346\216\247   \347\263\273   \347\273\237", nullptr));
        pushButtonVoice->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ControlWidget: public Ui_ControlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWIDGET_H
