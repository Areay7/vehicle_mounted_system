#ifndef MQTTLINK_H
#define MQTTLINK_H

#include <QObject>
#include <QtMqtt/qmqttclient.h>
#include <QDebug>
#include <QLabel>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
#include <QTimer>
#include "sysdatatype.h"

// 阿里云 连接参数
#define mqttHostUrl "iot-06z00aqr0zzjelx.mqtt.iothub.aliyuncs.com"
#define mqttPort "1883"
#define mqttClientId "k0etkov8nxp.vechilev_v1|securemode=2,signmethod=hmacsha256,timestamp=1713421876080|"
#define mqttUserName "vechilev_v1&k0etkov8nxp"
#define mqttUserPasswd "10016e531761eb3e36b48e48347c55e821cd7995a34b71d7d83234dc0a411e68"
#define PublishTopicName "/sys/k0etkov8nxp/vechilev_v1/thing/event/property/post"
#define SubTopicName "/sys/k0etkov8nxp/vechilev_v1/thing/event/property/post_reply"


// 阿里云 属性标识符
#define alyPosition "carPosition"               // 定位
#define alydoor "carDoor"                       // 车门
#define alyPressure "tirePressure"              // 胎压
#define alyBattery "batteryCapacity"            // 电池容量
#define alyLock "carLockOnoff"                  // 车锁
#define alyTrunk "trunkOnOff"                   // 后备箱
#define alyCarLigh "headLightOnOff"             // 车灯
#define alyInsideTemp "VehInsideTemp"           // 车内温度
#define alyHumidity "Humidity"                  // 湿度
#define alyAcMode "carAcMode"                   //空调模式
#define alyAcTemp "carAcTemp"                   //车空调温度
#define alyACSwitch "VehACSwitch"               //车空调开关


class mqttDevStatus
{
public:
    devSwitchStatus carDoorStatus;              // 车门状态
    devSwitchStatus ctirePressureStatus;        // 车胎状态
    devSwitchStatus carLockStatus;              // 车锁
    devSwitchStatus trunkStatus;                // 后备箱
    devSwitchStatus headLightStatus;            // 车灯
    devSwitchStatus vehACSwitchStatus;          // 空调开关

    AcMode carAcModeStatus;                     // 空调模式
    QString carPosition;                        // 定位

    float carAcTemp;                            // 空调温度
    int batteryCapacity;                        // 电池电量
    float vehInsideTemp;                        // 车内温度
    float veHumidity;                           // 车内湿度
};

class mqttLink : public QObject
{
    Q_OBJECT
public:
    explicit mqttLink(QObject *parent = nullptr);

    void mqttConnectSever(QString hostUrl, QString Port, QString clientId, QString userName, QString userPasswd);
    void mqttPublishTopic(QString topicName, mqttDevStatus &devStatus);
    void mqttSubscribe(QString topicName);
    void mqttDisConnect();
    void mqttConnect();

public slots:
    void timerTimeOut();
    void mqttReceive(const QByteArray &message, const QMqttTopicName &topic);

public:
    QMqttClient *myClient;
    QTimer *mqttTime;
    mqttDevStatus netDevStatus;
    QTimer *mainTimer;
    bool mqttReceFlag;

signals:

};

#endif // MQTTLINK_H
