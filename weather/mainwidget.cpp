#include "mainwidget.h"
#include "currentsituation.h"
#include "ui_mainwidget.h"
#include "controlwidget.h"
#include <QPixmap>
#include <QDebug>
#include <QProcess>
#include <QUrl>

#include "./remote/remotecontrol.h"
#include "./remote/remoteview.h"


extern devStatus mainDevIcon;
extern devStatus sysDevStatus;

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{

    ui->setupUi(this);
    // setWindowFlag(Qt::FramelessWindowHint); // 设置窗口无边框
    // 使用 QIcon 加载图像文件
//    QIcon icon(":/res/xiaomisu7_1.jpg");

    // 将 QIcon 转换为 QPixmap
//    QPixmap pixmap = icon.pixmap(QSize(670, 500)); // 设置图像大小，如果需要的话

    // 设置图像到 QLabel
//    ui->label->setPixmap(pixmap);

    mainWindow = new MainWindow(this); // 分配内存给 mainWindow 指针

    remoteWindow = new RemoteWindow(this);



/******************************************************************/
    //timer
    mainTimer = new QTimer();
    mainTimer->start(1000);
    connect(mainTimer,SIGNAL(timeout()),this,SLOT(timerTimeOut()));

    //mqtt initial
    netMqttMsg=new mqttLink();

    //initial extern variable
    initSysDevStatus();

    //get net location information
    currentLocationData =new baiduInverseData();
    currentLocationData->formattedAddress="天津市";
    currentLocationData->district="和平区";
    currentLocationData->town="天津站";
    currentLocationData->adcode="120112";
    ui->labelLocation->setText(currentLocationData->district+" "+currentLocationData->town);

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_btnOpenWeatherWindow_clicked()
{
    mainWindow->show(); // 显示主窗口
    hide(); // 隐藏当前窗口
}

void MainWidget::on_btnOpenSituationWindow_clicked()
{
    // 创建 CurrentSituation 窗口对象
    // CurrentSituation *situationWindow = new CurrentSituation();

    // 显示 CurrentSituation 窗口
    // situationWindow->show();

    RemoteViewWindow *remoteViewWindow = new RemoteViewWindow();
    remoteViewWindow->show();
    hide(); // 隐藏当前窗口
}





void MainWidget::on_btnOpenControlWindow_clicked()
{
    // 创建并显示 ControlWidget 窗口，并传递 MainWidget 对象的指针
    ControlWidget *controlWidget = new ControlWidget();
    controlWidget->show();


    hide();
}

/********************************************************************/
void MainWidget::on_enterMusic_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWidget::on_pushButtonMusicBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWidget::on_pushButtonEnvroBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWidget::on_enterEnvironment_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWidget::on_enterContorl_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

//void MainWidget::on_enterWeather_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(4);
//}


void MainWidget::on_pushButtonCorlBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//void MainWidget::on_pushButtonWeatherBack_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWidget::on_pushButtonMediaBack_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWidget::on_enterMediaPlayer_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(6);
//}
//void MainWidget::on_pushButtonMapBack_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWidget::on_pushButtonEnterMap_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(5);
//}


void MainWidget::setDevIcon(devSwitchStatus wifi, devSwitchStatus bluetooth)
{
    if(wifi==ON)
    {
        ui->labelWIFI->show();
    }
    else
    {
        ui->labelWIFI->hide();
    }

    if(bluetooth==ON)
    {
        ui->labelBluetooth->show();
    }
    else
    {
        ui->labelBluetooth->hide();
    }
}


void MainWidget::initSysDevStatus()
{
    sysDevStatus.linkWifiSSID="noting";
    sysDevStatus.wifiLinkStatus=false;
    sysDevStatus.doorStatus=OFF;
    sysDevStatus.carHybridStatus=OFF;
    sysDevStatus.carOilLockStatus=OFF;
    sysDevStatus.carSpecificStatus=OFF;
    sysDevStatus.carTrunkLockStatus=OFF;
//    sysDevStatus.carWinLockStatus=OFF;
    sysDevStatus.wifiStatus=OFF;
    sysDevStatus.bluetoothStatus=OFF;
    sysDevStatus.TermperSwitchStatus=OFF;
    sysDevStatus.HumSwitchStatus=OFF;
    sysDevStatus.condSWStatus=OFF;
    sysDevStatus.ledStatus=OFF;
    sysDevStatus.condMode=ACCOLD;
    sysDevStatus.currentSetTermper=26.0;
    sysDevStatus.currentSetHumidity=26.0;
    sysDevStatus.currentHumidity=55;
    sysDevStatus.currentTermper=20;




}


//void MainWidget::on_enterMusic_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(3);
//}

//void MainWidget::on_pushButtonMusicBack_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWidget::on_pushButtonEnvroBack_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWidget::on_enterEnvironment_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(1);
//}

//void MainWidget::on_enterContorl_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(2);
//}

//void MainWidget::on_enterWeather_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(4);
//}


//void MainWidget::on_pushButtonCorlBack_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWidget::on_pushButtonWeatherBack_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWidget::on_pushButtonMediaBack_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWidget::on_enterMediaPlayer_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(6);
//}
//void MainWidget::on_pushButtonMapBack_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWidget::on_pushButtonEnterMap_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(5);
//}


void MainWidget::catDoorLockStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    if(switchStatus==OFF)
    {
        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catLockON.png);}");
    }
    else if(switchStatus==ON)
    {
        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catLockOFF.png);}");
    }
    ui->pushButtonDoorLock->setStyleSheet(buttonStyle);
}

//void MainWidget::catOilLockStatusSeting(devSwitchStatus switchStatus)
//{
//    QString buttonStyle;
//    if(switchStatus==OFF)
//    {
//        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catOilLockON.png);}");
//    }
//    else if(switchStatus==ON)
//    {
//        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catOilLockOFF.png);}");
//    }
//    ui->pushButtonOilLOck->setStyleSheet(buttonStyle);
//}

void MainWidget::catTrunkLockStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    if(switchStatus==OFF)
    {
        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catTrunkON.png);}");
    }
    else if(switchStatus==ON)
    {
        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catTrunkOFF.png);}");
    }
    ui->pushButtonTrunkLock->setStyleSheet(buttonStyle);
}

//void MainWidget::catWinLockStatusSeting(devSwitchStatus switchStatus)
//{
//    QString buttonStyle;
//    if(switchStatus==OFF)
//    {
//        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catLockON.png);}");
//    }
//    else if(switchStatus==ON)
//    {
//        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catLockOFF.png);}");
//    }
//    ui->pushButtonWinLock->setStyleSheet(buttonStyle);
//}

void MainWidget::catHybridStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    if(switchStatus==OFF)
    {
        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catHybridON.png);}");
    }
    else if(switchStatus==ON)
    {
        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catHybridOFF.png);}");
    }
    ui->pushButtonHybrid->setStyleSheet(buttonStyle);
}

void MainWidget::catSpecificStatusSeting(devSwitchStatus switchStatus)
{
    QString buttonStyle;
    if(switchStatus==OFF)
    {
        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catSpecificON.png);}");
    }
    else if(switchStatus==ON)
    {
        buttonStyle= QString(" QPushButton {border-image: url(:/mainImage/catSpecificOFF.png);}");
    }
    ui->pushButtonSpecific->setStyleSheet(buttonStyle);
}



void MainWidget::on_pushButtonDoorLock_clicked()
{

    if(sysDevStatus.doorStatus==ON)
    {
        sysDevStatus.doorStatus=OFF;
    }
    else if( sysDevStatus.doorStatus==OFF)
    {
        sysDevStatus.doorStatus=ON;
    }
    catDoorLockStatusSeting(sysDevStatus.doorStatus);
}


//void MainWidget::on_pushButtonOilLOck_clicked()
//{

//    if(sysDevStatus.carOilLockStatus==ON)
//    {
//        sysDevStatus.carOilLockStatus=OFF;
//    }
//    else if( sysDevStatus.carOilLockStatus==OFF)
//    {
//        sysDevStatus.carOilLockStatus=ON;
//    }
//    catOilLockStatusSeting(sysDevStatus.carOilLockStatus);

//}


void MainWidget::on_pushButtonTrunkLock_clicked()
{

    if(sysDevStatus.carTrunkLockStatus==ON)
    {
        sysDevStatus.carTrunkLockStatus=OFF;
    }
    else if( sysDevStatus.carTrunkLockStatus==OFF)
    {
        sysDevStatus.carTrunkLockStatus=ON;
    }
    catTrunkLockStatusSeting(sysDevStatus.carTrunkLockStatus);
}


//void MainWidget::on_pushButtonWinLock_clicked()
//{

//    if(sysDevStatus.carWinLockStatus==ON)
//    {
//        sysDevStatus.carWinLockStatus=OFF;
//    }
//    else if( sysDevStatus.carWinLockStatus==OFF)
//    {
//        sysDevStatus.carWinLockStatus=ON;
//    }
//    catWinLockStatusSeting(sysDevStatus.carWinLockStatus);

//}


void MainWidget::on_pushButtonHybrid_clicked()
{

    if(sysDevStatus.carHybridStatus==ON)
    {
        sysDevStatus.carHybridStatus=OFF;
    }
    else if( sysDevStatus.carHybridStatus==OFF)
    {
        sysDevStatus.carHybridStatus=ON;
    }
    catHybridStatusSeting(sysDevStatus.carHybridStatus);
}


void MainWidget::on_pushButtonSpecific_clicked()
{

    if(sysDevStatus.carSpecificStatus==ON)
    {
        sysDevStatus.carSpecificStatus=OFF;
    }
    else if( sysDevStatus.carSpecificStatus==OFF)
    {
        sysDevStatus.carSpecificStatus=ON;
    }
    catSpecificStatusSeting(sysDevStatus.carSpecificStatus);
}

void MainWidget::timerTimeOut()
{
    static unsigned int cnt=0;

    cnt++;

    //接受远程APP端信息
    if(netMqttMsg->mqttReceFlag==true)
    {
        sysDevStatus.doorStatus=netMqttMsg->netDevStatus.carDoorStatus;
//        sysDevStatus.catTrunkLockStatus=netMqttMsg->netDevStatus.trunkStatus;
        sysDevStatus.TermperSwitchStatus=netMqttMsg->netDevStatus.vehACSwitchStatus;
        sysDevStatus.condSWStatus=netMqttMsg->netDevStatus.vehACSwitchStatus;
        sysDevStatus.ledStatus=netMqttMsg->netDevStatus.headLightStatus;
        sysDevStatus.condMode=netMqttMsg->netDevStatus.carAcModeStatus;
        sysDevStatus.currentSetTermper=netMqttMsg->netDevStatus.carAcTemp;

        netMqttMsg->mqttReceFlag=false;
    }
    // 刷新状态
    setDevIcon(sysDevStatus.wifiStatus,sysDevStatus.bluetoothStatus);
    catDoorLockStatusSeting(sysDevStatus.doorStatus);
//    carWinLockStatusSeting(sysDevStatus.carWinLockStatus);
    catTrunkLockStatusSeting(sysDevStatus.carTrunkLockStatus);
//    catOilLockStatusSeting(sysDevStatus.carOilLockStatus);

    //发送到远程APP端
    mqttDevStatus test;
    if(cnt%5==0)
    {
        currentLocationData->currentLat=QString::number(sysDevStatus.GPSLat,'f',7);
        currentLocationData->currentLon=QString::number(sysDevStatus.GPSLon,'f',7);
        qDebug()<<"lon:"<< currentLocationData->currentLon<<"lat:"<<currentLocationData->currentLat;

        // acquireCurrentNetLocation(currentLocationData);
        sysDevStatus.GPSAddress=currentLocationData->formattedAddress;
        qDebug()<<sysDevStatus.GPSAddress;

        test.batteryCapacity=87;
        test.vehInsideTemp=sysDevStatus.currentTermper;
        test.veHumidity=sysDevStatus.currentHumidity;
        test.carAcModeStatus=sysDevStatus.condMode;
        test.carDoorStatus=sysDevStatus.doorStatus;
        test.trunkStatus=sysDevStatus.carTrunkLockStatus;
        test.carLockStatus=sysDevStatus.doorStatus;
        test.carPosition=sysDevStatus.GPSAddress;
        test.headLightStatus=sysDevStatus.ledStatus;
        test.carAcTemp=sysDevStatus.currentSetTermper;
        test.vehACSwitchStatus=sysDevStatus.condSWStatus;


        netMqttMsg->mqttPublishTopic(PublishTopicName,test);
    }

    if(cnt%60==0)
    {
        if(sysDevStatus.wifiLinkStatus==true)
        {
//            bool result=mainCardWeather.acquireNetWeather(mainCardWeather.nowWeather,mainCardWeather.nowIndexes,mainCardWeather.nowAlerts,mainCardWeather.forecasts,mainCardWeather.forecastsHours);
//            if(result)
//            {
//                setMainUiNetWeather(mainCardWeather.nowWeather,mainCardWeather.nowIndexes,mainCardWeather.nowAlerts,mainCardWeather.forecasts,mainCardWeather.forecastsHours);
//            }
        }
    }
}


void MainWidget::on_btnOpenRemoteWindow_clicked()
{
    remoteWindow->show();

    hide();
}

