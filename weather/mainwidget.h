#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "mainwindow.h"
#include "./remote/remotecontrol.h"
#include "./remote/remoteview.h"
#include "./opencvServer/opencvWindow.h"

#include <QTimer>
//#include <QMediaPlayer>
#include <QUrl>
#include "http.h"
#include "controlwidget.h"
#include "mqttlink.h"
#include "battery.h"


//#include "gps.h"
//#include "texttovoice.h"
//#include "netweather.h"

//const QString baiduInversenUrl = "http://api.map.baidu.com/reverse_geocoding/v3/?ak=%1&output=json&coordtype=wgs84ll&location=%2,%3&";
//const QString baiduAk = "dyAOxKuj5E4wOsukUNzOcmZKIxPdo8sC";

//class musicwidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class baiduInverseData
{
public:
    QString currentLat;
    QString currentLon;
    QString formattedAddress;
    QString district;
    QString town;
    QString adcode;
};

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public:
    void initSysDevStatus();
    void catDoorLockStatusSeting(devSwitchStatus switchStatus);
    void catOilLockStatusSeting(devSwitchStatus switchStatus);
    void catTrunkLockStatusSeting(devSwitchStatus switchStatus);
    void catWinLockStatusSeting(devSwitchStatus switchStatus);
    void catHybridStatusSeting(devSwitchStatus switchStatus);
    void catSpecificStatusSeting(devSwitchStatus switchStatus);

//    bool acquireCurrentNetLocation(baiduInverseData *Data);

//    void setMainWeatherIcon(QFrame *WeaBack, QWidget *WeaSubBack,QLabel *WeaSaying,QLabel *WeaTitle, QString nowWeather,int index);
//    void setMainUiNetWeather(nowWeatherNet& Weather,nowIndexesNet &Indexes,nowAlertsNet& Alerts,forecastsNet& forecasts,forecastsHoursNet& forecastsHours);
    void setDevIcon(devSwitchStatus wifi,devSwitchStatus bluetooth);

//    void getGpsData(void);

private slots:
    void on_btnOpenWeatherWindow_clicked();

    void on_btnOpenSituationWindow_clicked();

    void on_btnOpenControlWindow_clicked();

private slots:
    void timerTimeOut();
    void on_pushButtonHybrid_clicked();
    void on_pushButtonSpecific_clicked();


    void on_pushButtonDoorLock_clicked();

    void on_pushButtonTrunkLock_clicked();

//    void on_pushButtonOilLOck_clicked();

//    void on_pushButtonWinLock_clicked();


    void on_enterMusic_clicked();
    void on_pushButtonMusicBack_clicked();
    void on_pushButtonEnvroBack_clicked();
    void on_enterEnvironment_clicked();
    void on_enterContorl_clicked();
    void on_pushButtonCorlBack_clicked();








//    void on_pushButtonOilLOck_clicked();

//    void on_pushButtonWinLock_clicked();


    void on_btnOpenRemoteWindow_clicked();

    void on_pushButtonEnterMap_clicked();

private:
    Ui::MainWidget *ui;
    MainWindow *mainWindow;
    RemoteWindow *remoteWindow;
    RemoteView *remoteViewWindow;
    OpencvWindow *opencvWindow;

private:
    QTimer *mainTimer;
    baiduInverseData *currentLocationData;
//    gps *myGpsThread;
   // textToVoice *mainTextToVoice;
//    QMediaPlayer *player;
//    Netweather mainCardWeather;
    mqttLink *netMqttMsg;

private:
    Battery *battery;
};

#endif // MAINWIDGET_H
