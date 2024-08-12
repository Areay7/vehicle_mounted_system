
/****************************************************************
*   @project         Viches                                     *
*   @file            controlwidget.h                            *
*   @brief           Abstract                                   *
*   @author          Areay7                                     *
*   @emial           2507549477@qq.com                          *
*   @blog            www.myblog.areay7.cn                       *
*   @date            2024-07-01                                 *
*   @Copyright:      Copyright (c) 2024 MQ. All rights reserved.*
*****************************************************************/


#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QContextMenuEvent>
#include <QMenu>
#include <QProcess>
#include "mainwidget.h"
#include "mqttlink.h"
#include "record.h"
#include "specch.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class ControlWidget;
}
QT_END_NAMESPACE

class devStatus
{
public:
    devSwitchStatus ledStatus;
    devSwitchStatus doorStatus;
    devSwitchStatus condSWStatus;               // 空调
    devSwitchStatus dehumdifierStatus;          // 加湿器
    devSwitchStatus wifiStatus;
    devSwitchStatus bluetoothStatus;
    devSwitchStatus carOilLockStatus;
    devSwitchStatus carTrunkLockStatus;
    devSwitchStatus carHybridStatus;
    devSwitchStatus carSpecificStatus;

    AcMode condMode;                            // 空调模式
    double currentSetTermper;                   // 空调温度
    double currentSetHumidity;                  // 加湿器温度
    double currentTermper;
    double currentHumidity;

    devSwitchStatus TermperSwitchStatus;
    devSwitchStatus HumSwitchStatus;
    QString GPSAddress;                         // 当前位置
    double GPSLat;
    double GPSLon;
    bool wifiLinkStatus;
    QString linkWifiSSID;
};


class ControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWidget(QWidget *parent = nullptr);
    ~ControlWidget();
   void voiceControl(QString Text);

protected:
    // 重写父类方法
    void contextMenuEvent(QContextMenuEvent *event);
private:
//    MainWidget *mMainWidget;

private:
    Ui::ControlWidget *ui;

    QMenu *mExitMenu;   // 右键退出的菜单
    QAction *mExitAct;  // 退出行为 - 菜单项
    QAction *mReturnAct; // 返回行为 - 菜单项

public slots:
    void returnToMainWidget();


/*************************************************************/
private slots:

    void on_pushButtonSetLED_clicked();

    void on_pushButtonSetDoor_clicked();

    void on_pushButtonSetMode_clicked();

    void on_pushButtonTemperSw_clicked();

    void on_pushButtonAdd_pressed();

    void on_pushButtonAdd_released();

    void on_pushButtonSub_pressed();

    void on_pushButtonSub_released();

    void on_pushButtonHumSw_clicked();

    void on_pushButtonSetHumAdd_pressed();

    void on_pushButtonSetHumAdd_released();

    void on_pushButtonSetHumSub_pressed();

    void on_pushButtonSetHumSub_released();

    void timerTimeOut();
    void on_pushButtonSetWIFI_clicked();

    void on_pushButtonSetBlue_clicked();

//    void on_pushButtonVoice_pressed();

//    void on_pushButtonVoice_released();


    void on_pushButtonEdit_clicked();

    void on_pushButtonVoice_pressed();

    void on_pushButtonVoice_released();

private:
    void ledStatusSeting(devSwitchStatus switchStatus);
    void doorStatusSeting(devSwitchStatus switchStatus);
    void condSwStatusSeting(devSwitchStatus switchStatus);
    void condModeSeting(AcMode modeStatus);

    void dehumSwStatusSeting(devSwitchStatus switchStatus);
    void wifiSwStatusSeting(devSwitchStatus switchStatus);
    void bluetoothSwStatusSeting(devSwitchStatus switchStatus);

    QTimer *controlTimer;
    specch *voicSpecch;
    record * recordVoiceThread;
    QString voiceToText;

    QProcess *m_process;
    QStringList ledArguments;

    bool wifiLinkStatus;
    QString linkWifiSSID;
};

#endif // CONTROLWIDGET_H
