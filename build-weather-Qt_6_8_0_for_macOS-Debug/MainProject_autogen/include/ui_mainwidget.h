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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QFrame *frame;
    QLabel *labelBattery;
    QLabel *labelBluetooth;
    QLabel *labelWIFI;
    QLabel *labelSignal;
    QStackedWidget *stackedWidget;
    QWidget *main;
    QPushButton *btnOpenControlWindow;
    QPushButton *btnOpenSituationWindow;
    QPushButton *btnOpenWeatherWindow;
    QPushButton *enterEnvironment;
    QPushButton *enterMusic;
    QFrame *line;
    QPushButton *btnOpenWeatherWindow_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonDoorLock;
    QLabel *labelDoorLock;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonOilLOck;
    QLabel *labelOilLock;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonTrunkLock;
    QLabel *labelTrunkLock;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelWinLock;
    QPushButton *pushButtonWinLock;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelHybrid;
    QPushButton *pushButtonHybrid;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelSpecific;
    QPushButton *pushButtonSpecific;
    QFrame *frameWeather;
    QLabel *labelPoem;
    QLabel *labelWeather;
    QFrame *line_9;
    QFrame *line_10;
    QWidget *widgetWeather;
    QLabel *labelOutsideTemp;
    QLabel *labelLocation;
    QLabel *labelWeaIcon;
    QLabel *labelDate;
    QLabel *labelDateSub;
    QLabel *labelCatTitle;
    QLabel *labelCatIcon;
    QWidget *catOther;
    QLabel *labelTrun;
    QFrame *line_3;
    QLabel *labelSetLeft;
    QFrame *line_4;
    QLabel *labelxxx;
    QFrame *line_5;
    QLabel *labelWind;
    QFrame *line_6;
    QLabel *labelSetRight;
    QFrame *line_7;
    QLabel *labelxxxT;
    QFrame *line_8;
    QLabel *labelHot;
    QLabel *labelIcon;
    QPushButton *pushButtonEnterMap;
    QLabel *labelCatTitle_2;
    QWidget *environmentPenal;
    QWidget *contorl;
    QPushButton *pushButtonCorlBack;
    QWidget *musicPlayer;
    QWidget *weather;
    QWidget *map;
    QWidget *mediaPlyer;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(894, 625);
        frame = new QFrame(MainWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 0, 891, 31));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelBattery = new QLabel(frame);
        labelBattery->setObjectName("labelBattery");
        labelBattery->setGeometry(QRect(840, 0, 41, 31));
        labelBattery->setStyleSheet(QString::fromUtf8(" \n"
"image: url(:/mainImage/Battery.png);"));
        labelBluetooth = new QLabel(frame);
        labelBluetooth->setObjectName("labelBluetooth");
        labelBluetooth->setGeometry(QRect(810, 0, 31, 31));
        labelBluetooth->setStyleSheet(QString::fromUtf8(" \n"
"image: url(:/mainImage/Bluetooth2x.png);"));
        labelWIFI = new QLabel(frame);
        labelWIFI->setObjectName("labelWIFI");
        labelWIFI->setGeometry(QRect(780, 0, 31, 31));
        labelWIFI->setStyleSheet(QString::fromUtf8(" \n"
" \n"
"image: url(:/mainImage/Wifi2x.png);"));
        labelSignal = new QLabel(frame);
        labelSignal->setObjectName("labelSignal");
        labelSignal->setGeometry(QRect(-10, 0, 61, 31));
        labelSignal->setStyleSheet(QString::fromUtf8(" \n"
"image: url(:/mainImage/Signal.png);"));
        stackedWidget = new QStackedWidget(MainWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 30, 891, 621));
        stackedWidget->setStyleSheet(QString::fromUtf8("color:#29B7CB;"));
        main = new QWidget();
        main->setObjectName("main");
        main->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(234, 243, 244);"));
        btnOpenControlWindow = new QPushButton(main);
        btnOpenControlWindow->setObjectName("btnOpenControlWindow");
        btnOpenControlWindow->setGeometry(QRect(720, 220, 151, 51));
        QFont font;
        font.setPointSize(20);
        btnOpenControlWindow->setFont(font);
        btnOpenControlWindow->setStyleSheet(QString::fromUtf8("\n"
" QPushButton:pressed {\n"
"	border-image: url(:/mainImage/mainControlPress.png);\n"
" }\n"
" QPushButton {\n"
"	border-image: url(:/mainImage/mainControlRelease.png);\n"
" }"));
        btnOpenSituationWindow = new QPushButton(main);
        btnOpenSituationWindow->setObjectName("btnOpenSituationWindow");
        btnOpenSituationWindow->setGeometry(QRect(720, 520, 151, 51));
        btnOpenSituationWindow->setStyleSheet(QString::fromUtf8("\n"
" QPushButton:pressed {\n"
"	border-image: url(:/mainImage/mainControlPress.png);\n"
" }\n"
" QPushButton {\n"
"	border-image: url(:/mainImage/mainControlRelease.png);\n"
" }"));
        btnOpenWeatherWindow = new QPushButton(main);
        btnOpenWeatherWindow->setObjectName("btnOpenWeatherWindow");
        btnOpenWeatherWindow->setGeometry(QRect(720, 400, 151, 51));
        btnOpenWeatherWindow->setStyleSheet(QString::fromUtf8("\n"
" QPushButton:pressed {\n"
" \n"
"	border-image: url(:/mainImage/mainWeatherpress.png);\n"
" }\n"
" QPushButton {\n"
" \n"
"	border-image: url(:/mainImage/mainWeatherRelease.png);\n"
" }"));
        enterEnvironment = new QPushButton(main);
        enterEnvironment->setObjectName("enterEnvironment");
        enterEnvironment->setGeometry(QRect(720, 280, 151, 51));
        enterEnvironment->setStyleSheet(QString::fromUtf8("\n"
" QPushButton:pressed {\n"
"	border-image: url(:/mainImage/mainRecordPress.png);\n"
" }\n"
" QPushButton {\n"
"	border-image: url(:/mainImage/mainRecordRelease.png);\n"
" }"));
        enterMusic = new QPushButton(main);
        enterMusic->setObjectName("enterMusic");
        enterMusic->setGeometry(QRect(720, 340, 151, 51));
        enterMusic->setStyleSheet(QString::fromUtf8("\n"
" QPushButton:pressed {\n"
"	border-image: url(:/mainImage/mainMusicPress.png);\n"
" }\n"
" QPushButton {\n"
"	border-image: url(:/mainImage/mainMusicRelease.png);\n"
" }"));
        line = new QFrame(main);
        line->setObjectName("line");
        line->setGeometry(QRect(700, 0, 20, 571));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        btnOpenWeatherWindow_2 = new QPushButton(main);
        btnOpenWeatherWindow_2->setObjectName("btnOpenWeatherWindow_2");
        btnOpenWeatherWindow_2->setGeometry(QRect(720, 460, 151, 51));
        btnOpenWeatherWindow_2->setStyleSheet(QString::fromUtf8("\n"
" QPushButton:pressed {\n"
" \n"
"	border-image: url(:/mainImage/mainWeatherpress.png);\n"
" }\n"
" QPushButton {\n"
" \n"
"	border-image: url(:/mainImage/mainWeatherRelease.png);\n"
" }"));
        layoutWidget = new QWidget(main);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 330, 109, 171));
        verticalLayout2 = new QVBoxLayout(layoutWidget);
        verticalLayout2->setObjectName("verticalLayout2");
        verticalLayout2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonDoorLock = new QPushButton(layoutWidget);
        pushButtonDoorLock->setObjectName("pushButtonDoorLock");
        pushButtonDoorLock->setMinimumSize(QSize(41, 41));
        pushButtonDoorLock->setMaximumSize(QSize(41, 41));
        pushButtonDoorLock->setStyleSheet(QString::fromUtf8("border-image: url(:/mainImage/catLockON.png);"));

        horizontalLayout->addWidget(pushButtonDoorLock);

        labelDoorLock = new QLabel(layoutWidget);
        labelDoorLock->setObjectName("labelDoorLock");
        labelDoorLock->setMinimumSize(QSize(50, 0));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(15);
        labelDoorLock->setFont(font1);

        horizontalLayout->addWidget(labelDoorLock);


        verticalLayout2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButtonOilLOck = new QPushButton(layoutWidget);
        pushButtonOilLOck->setObjectName("pushButtonOilLOck");
        pushButtonOilLOck->setMinimumSize(QSize(41, 41));
        pushButtonOilLOck->setMaximumSize(QSize(41, 41));
        pushButtonOilLOck->setStyleSheet(QString::fromUtf8("border-image: url(:/mainImage/catOilLockON.png);"));

        horizontalLayout_2->addWidget(pushButtonOilLOck);

        labelOilLock = new QLabel(layoutWidget);
        labelOilLock->setObjectName("labelOilLock");
        labelOilLock->setFont(font1);

        horizontalLayout_2->addWidget(labelOilLock);


        verticalLayout2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButtonTrunkLock = new QPushButton(layoutWidget);
        pushButtonTrunkLock->setObjectName("pushButtonTrunkLock");
        pushButtonTrunkLock->setMinimumSize(QSize(41, 41));
        pushButtonTrunkLock->setMaximumSize(QSize(41, 41));
        pushButtonTrunkLock->setStyleSheet(QString::fromUtf8("border-image: url(:/mainImage/catTrunkON.png);"));

        horizontalLayout_3->addWidget(pushButtonTrunkLock);

        labelTrunkLock = new QLabel(layoutWidget);
        labelTrunkLock->setObjectName("labelTrunkLock");
        labelTrunkLock->setFont(font1);

        horizontalLayout_3->addWidget(labelTrunkLock);


        verticalLayout2->addLayout(horizontalLayout_3);

        layoutWidget_2 = new QWidget(main);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(590, 330, 116, 171));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        labelWinLock = new QLabel(layoutWidget_2);
        labelWinLock->setObjectName("labelWinLock");
        labelWinLock->setMinimumSize(QSize(50, 0));
        labelWinLock->setFont(font1);

        horizontalLayout_4->addWidget(labelWinLock);

        pushButtonWinLock = new QPushButton(layoutWidget_2);
        pushButtonWinLock->setObjectName("pushButtonWinLock");
        pushButtonWinLock->setMinimumSize(QSize(41, 41));
        pushButtonWinLock->setMaximumSize(QSize(41, 41));
        pushButtonWinLock->setStyleSheet(QString::fromUtf8("border-image: url(:/mainImage/catLockON.png);"));

        horizontalLayout_4->addWidget(pushButtonWinLock);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        labelHybrid = new QLabel(layoutWidget_2);
        labelHybrid->setObjectName("labelHybrid");
        labelHybrid->setFont(font1);

        horizontalLayout_5->addWidget(labelHybrid);

        pushButtonHybrid = new QPushButton(layoutWidget_2);
        pushButtonHybrid->setObjectName("pushButtonHybrid");
        pushButtonHybrid->setMinimumSize(QSize(41, 41));
        pushButtonHybrid->setMaximumSize(QSize(41, 41));
        pushButtonHybrid->setStyleSheet(QString::fromUtf8(" \n"
"border-image: url(:/mainImage/catHybridON.png);"));

        horizontalLayout_5->addWidget(pushButtonHybrid);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        labelSpecific = new QLabel(layoutWidget_2);
        labelSpecific->setObjectName("labelSpecific");
        labelSpecific->setFont(font1);

        horizontalLayout_6->addWidget(labelSpecific);

        pushButtonSpecific = new QPushButton(layoutWidget_2);
        pushButtonSpecific->setObjectName("pushButtonSpecific");
        pushButtonSpecific->setMinimumSize(QSize(41, 41));
        pushButtonSpecific->setMaximumSize(QSize(41, 41));
        pushButtonSpecific->setStyleSheet(QString::fromUtf8(" \n"
"border-image: url(:/mainImage/catSpecificON.png);"));

        horizontalLayout_6->addWidget(pushButtonSpecific);


        verticalLayout_3->addLayout(horizontalLayout_6);

        frameWeather = new QFrame(main);
        frameWeather->setObjectName("frameWeather");
        frameWeather->setGeometry(QRect(0, 0, 711, 251));
        frameWeather->setStyleSheet(QString::fromUtf8("QFrame#frameWeather\n"
"{\n"
"border-image: url(:/mainImage/wertherRainBack2.jpg);\n"
"\n"
"}\n"
""));
        frameWeather->setFrameShape(QFrame::StyledPanel);
        frameWeather->setFrameShadow(QFrame::Raised);
        labelPoem = new QLabel(frameWeather);
        labelPoem->setObjectName("labelPoem");
        labelPoem->setGeometry(QRect(17, 150, 241, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(14);
        font2.setBold(true);
        labelPoem->setFont(font2);
        labelPoem->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:#29B7CB;"));
        labelWeather = new QLabel(frameWeather);
        labelWeather->setObjectName("labelWeather");
        labelWeather->setGeometry(QRect(240, 170, 111, 20));
        labelWeather->setFont(font2);
        labelWeather->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:#29B7CB;"));
        line_9 = new QFrame(frameWeather);
        line_9->setObjectName("line_9");
        line_9->setGeometry(QRect(100, 1, 3, 35));
        QFont font3;
        font3.setBold(false);
        line_9->setFont(font3);
        line_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        line_9->setFrameShape(QFrame::Shape::VLine);
        line_9->setFrameShadow(QFrame::Shadow::Sunken);
        line_10 = new QFrame(frameWeather);
        line_10->setObjectName("line_10");
        line_10->setGeometry(QRect(220, 0, 3, 35));
        line_10->setFont(font3);
        line_10->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        line_10->setFrameShape(QFrame::Shape::VLine);
        line_10->setFrameShadow(QFrame::Shadow::Sunken);
        widgetWeather = new QWidget(frameWeather);
        widgetWeather->setObjectName("widgetWeather");
        widgetWeather->setGeometry(QRect(0, 30, 341, 111));
        widgetWeather->setStyleSheet(QString::fromUtf8("QWidget#widgetWeather\n"
"{\n"
"background: #29B7CB;\n"
"}\n"
""));
        labelOutsideTemp = new QLabel(widgetWeather);
        labelOutsideTemp->setObjectName("labelOutsideTemp");
        labelOutsideTemp->setGeometry(QRect(50, 20, 81, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font4.setPointSize(28);
        labelOutsideTemp->setFont(font4);
        labelOutsideTemp->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:white;"));
        labelLocation = new QLabel(widgetWeather);
        labelLocation->setObjectName("labelLocation");
        labelLocation->setGeometry(QRect(40, 70, 101, 16));
        labelLocation->setFont(font1);
        labelLocation->setStyleSheet(QString::fromUtf8("\n"
"background: rgba(0,0,0,0%);\n"
"color:white;"));
        labelWeaIcon = new QLabel(widgetWeather);
        labelWeaIcon->setObjectName("labelWeaIcon");
        labelWeaIcon->setGeometry(QRect(260, 10, 49, 38));
        QFont font5;
        font5.setPointSize(15);
        labelWeaIcon->setFont(font5);
        labelWeaIcon->setStyleSheet(QString::fromUtf8("border-image: url(:/mainImage/RainIcon.png);\n"
"background: rgba(0,0,0,0%);"));
        labelDate = new QLabel(widgetWeather);
        labelDate->setObjectName("labelDate");
        labelDate->setGeometry(QRect(240, 50, 81, 20));
        QFont font6;
        font6.setPointSize(11);
        labelDate->setFont(font6);
        labelDate->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:white;"));
        labelDateSub = new QLabel(widgetWeather);
        labelDateSub->setObjectName("labelDateSub");
        labelDateSub->setGeometry(QRect(260, 70, 54, 16));
        labelDateSub->setFont(font6);
        labelDateSub->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%);\n"
"color:white;"));
        labelCatTitle = new QLabel(main);
        labelCatTitle->setObjectName("labelCatTitle");
        labelCatTitle->setGeometry(QRect(280, 290, 161, 31));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font7.setPointSize(15);
        font7.setBold(true);
        labelCatTitle->setFont(font7);
        labelCatTitle->setStyleSheet(QString::fromUtf8("color:#29B7CB;"));
        labelCatIcon = new QLabel(main);
        labelCatIcon->setObjectName("labelCatIcon");
        labelCatIcon->setGeometry(QRect(120, 330, 461, 171));
        labelCatIcon->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/res/xiaomisu7_1.jpg);"));
        catOther = new QWidget(main);
        catOther->setObjectName("catOther");
        catOther->setGeometry(QRect(0, 520, 701, 61));
        catOther->setStyleSheet(QString::fromUtf8("QWidget#catOther\n"
"{\n"
"border-image: url(:/mainImage/mainother.png);\n"
"}\n"
""));
        labelTrun = new QLabel(catOther);
        labelTrun->setObjectName("labelTrun");
        labelTrun->setGeometry(QRect(58, 15, 30, 30));
        labelTrun->setMinimumSize(QSize(30, 30));
        labelTrun->setMaximumSize(QSize(30, 30));
        labelTrun->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%); \n"
"border-image: url(:/mainImage/main1.png);"));
        line_3 = new QFrame(catOther);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(121, 5, 3, 45));
        line_3->setStyleSheet(QString::fromUtf8(""));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        labelSetLeft = new QLabel(catOther);
        labelSetLeft->setObjectName("labelSetLeft");
        labelSetLeft->setGeometry(QRect(157, 15, 30, 30));
        labelSetLeft->setMinimumSize(QSize(30, 30));
        labelSetLeft->setMaximumSize(QSize(30, 30));
        labelSetLeft->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%); \n"
"border-image: url(:/mainImage/main2.png);"));
        line_4 = new QFrame(catOther);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(220, 5, 3, 45));
        line_4->setFrameShape(QFrame::Shape::VLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        labelxxx = new QLabel(catOther);
        labelxxx->setObjectName("labelxxx");
        labelxxx->setGeometry(QRect(245, 14, 51, 31));
        labelxxx->setMinimumSize(QSize(30, 30));
        labelxxx->setMaximumSize(QSize(111, 111));
        labelxxx->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%); \n"
"border-image: url(:/mainImage/main3.png);"));
        line_5 = new QFrame(catOther);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(319, 5, 3, 45));
        line_5->setFrameShape(QFrame::Shape::VLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        labelWind = new QLabel(catOther);
        labelWind->setObjectName("labelWind");
        labelWind->setGeometry(QRect(355, 15, 30, 30));
        labelWind->setMinimumSize(QSize(30, 30));
        labelWind->setMaximumSize(QSize(30, 30));
        labelWind->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%); \n"
"border-image: url(:/mainImage/main4.png);"));
        line_6 = new QFrame(catOther);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(418, 5, 3, 45));
        line_6->setFrameShape(QFrame::Shape::VLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        labelSetRight = new QLabel(catOther);
        labelSetRight->setObjectName("labelSetRight");
        labelSetRight->setGeometry(QRect(454, 15, 30, 30));
        labelSetRight->setMinimumSize(QSize(30, 30));
        labelSetRight->setMaximumSize(QSize(30, 30));
        labelSetRight->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%); \n"
"border-image: url(:/mainImage/main6.png);"));
        line_7 = new QFrame(catOther);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(517, 5, 3, 45));
        line_7->setFrameShape(QFrame::Shape::VLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);
        labelxxxT = new QLabel(catOther);
        labelxxxT->setObjectName("labelxxxT");
        labelxxxT->setGeometry(QRect(543, 15, 51, 30));
        labelxxxT->setMinimumSize(QSize(30, 30));
        labelxxxT->setMaximumSize(QSize(111, 111));
        labelxxxT->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%); \n"
"border-image: url(:/mainImage/main5.png);"));
        line_8 = new QFrame(catOther);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(616, 5, 3, 45));
        line_8->setFrameShape(QFrame::Shape::VLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);
        labelHot = new QLabel(catOther);
        labelHot->setObjectName("labelHot");
        labelHot->setGeometry(QRect(652, 15, 30, 30));
        labelHot->setMinimumSize(QSize(30, 30));
        labelHot->setMaximumSize(QSize(30, 30));
        labelHot->setStyleSheet(QString::fromUtf8("background: rgba(0,0,0,0%); \n"
"border-image: url(:/mainImage/main7.png);"));
        labelIcon = new QLabel(main);
        labelIcon->setObjectName("labelIcon");
        labelIcon->setGeometry(QRect(730, 20, 121, 121));
        labelIcon->setStyleSheet(QString::fromUtf8("border-image: url(:/mainImage/mainTitle.png);"));
        pushButtonEnterMap = new QPushButton(main);
        pushButtonEnterMap->setObjectName("pushButtonEnterMap");
        pushButtonEnterMap->setGeometry(QRect(720, 160, 151, 51));
        pushButtonEnterMap->setStyleSheet(QString::fromUtf8("\n"
" QPushButton:pressed {\n"
"	border-image: url(:/mainImage/mainMusicPress.png);\n"
" }\n"
" QPushButton {\n"
"	border-image: url(:/mainImage/mainMusicRelease.png);\n"
" }"));
        labelCatTitle_2 = new QLabel(main);
        labelCatTitle_2->setObjectName("labelCatTitle_2");
        labelCatTitle_2->setGeometry(QRect(280, 260, 161, 31));
        labelCatTitle_2->setFont(font7);
        labelCatTitle_2->setStyleSheet(QString::fromUtf8("color:#29B7CB;"));
        stackedWidget->addWidget(main);
        environmentPenal = new QWidget();
        environmentPenal->setObjectName("environmentPenal");
        stackedWidget->addWidget(environmentPenal);
        contorl = new QWidget();
        contorl->setObjectName("contorl");
        pushButtonCorlBack = new QPushButton(contorl);
        pushButtonCorlBack->setObjectName("pushButtonCorlBack");
        pushButtonCorlBack->setGeometry(QRect(0, 0, 51, 51));
        pushButtonCorlBack->setStyleSheet(QString::fromUtf8(" QPushButton:hover {\n"
"	border-image: url(:/image/musicbackhover.png);\n"
" }\n"
" QPushButton {\n"
"	border-image: url(:/image/musicback.png);\n"
" }\n"
""));
        stackedWidget->addWidget(contorl);
        musicPlayer = new QWidget();
        musicPlayer->setObjectName("musicPlayer");
        stackedWidget->addWidget(musicPlayer);
        weather = new QWidget();
        weather->setObjectName("weather");
        stackedWidget->addWidget(weather);
        map = new QWidget();
        map->setObjectName("map");
        stackedWidget->addWidget(map);
        mediaPlyer = new QWidget();
        mediaPlyer->setObjectName("mediaPlyer");
        stackedWidget->addWidget(mediaPlyer);

        retranslateUi(MainWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "XIAOMI-SU7\350\275\246\350\275\275\347\263\273\347\273\237", nullptr));
        labelBattery->setText(QString());
        labelBluetooth->setText(QString());
        labelWIFI->setText(QString());
        labelSignal->setText(QString());
        btnOpenControlWindow->setText(QString());
        btnOpenSituationWindow->setText(QString());
        btnOpenWeatherWindow->setText(QString());
        enterEnvironment->setText(QString());
        enterMusic->setText(QString());
        btnOpenWeatherWindow_2->setText(QString());
        pushButtonDoorLock->setText(QString());
        labelDoorLock->setText(QCoreApplication::translate("MainWidget", "Door", nullptr));
        pushButtonOilLOck->setText(QString());
        labelOilLock->setText(QCoreApplication::translate("MainWidget", "Fuel", nullptr));
        pushButtonTrunkLock->setText(QString());
        labelTrunkLock->setText(QCoreApplication::translate("MainWidget", "Trunk", nullptr));
        labelWinLock->setText(QCoreApplication::translate("MainWidget", "Window", nullptr));
        pushButtonWinLock->setText(QString());
        labelHybrid->setText(QCoreApplication::translate("MainWidget", "Hybrid", nullptr));
        pushButtonHybrid->setText(QString());
        labelSpecific->setText(QCoreApplication::translate("MainWidget", "Specific", nullptr));
        pushButtonSpecific->setText(QString());
        labelPoem->setText(QCoreApplication::translate("MainWidget", "\344\275\206\347\233\274\351\243\216\351\233\250\346\235\245\357\274\214\350\203\275\347\225\231\344\275\240\345\234\250\346\255\244", nullptr));
        labelWeather->setText(QCoreApplication::translate("MainWidget", "-------\345\260\217\351\233\250", nullptr));
        labelOutsideTemp->setText(QCoreApplication::translate("MainWidget", "  21\302\260C", nullptr));
        labelLocation->setText(QCoreApplication::translate("MainWidget", "\345\244\251\346\264\245\345\270\202 \345\222\214\345\271\263\345\214\272", nullptr));
        labelWeaIcon->setText(QString());
        labelDate->setText(QCoreApplication::translate("MainWidget", "2024/4/15", nullptr));
        labelDateSub->setText(QCoreApplication::translate("MainWidget", "\346\230\237\346\234\237\345\233\233", nullptr));
        labelCatTitle->setText(QCoreApplication::translate("MainWidget", "            BASE  CONTROL", nullptr));
        labelCatIcon->setText(QString());
        labelTrun->setText(QString());
        labelSetLeft->setText(QString());
        labelxxx->setText(QString());
        labelWind->setText(QString());
        labelSetRight->setText(QString());
        labelxxxT->setText(QString());
        labelHot->setText(QString());
        labelIcon->setText(QString());
        pushButtonEnterMap->setText(QString());
        labelCatTitle_2->setText(QCoreApplication::translate("MainWidget", "                XIAOMISU7", nullptr));
        pushButtonCorlBack->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
