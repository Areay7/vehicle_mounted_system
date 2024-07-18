#include "mqttlink.h"
#include "http.h"
#include "controlwidget.h"

extern devStatus sysDevStatus;

mqttLink::mqttLink(QObject *parent)
    : QObject{parent}
{
    mainTimer = new QTimer();
    mainTimer->start(5000);
    connect(mainTimer, SIGNAL(timeout()), this,SLOT(timerTimeOut()));

    myClient = new QMqttClient();

    netDevStatus.carAcModeStatus = ACCOLD;
    netDevStatus.carDoorStatus = OFF;
    netDevStatus.carLockStatus = OFF;
    netDevStatus.ctirePressureStatus = ON;
    netDevStatus.headLightStatus = OFF;
    netDevStatus.trunkStatus = OFF;
    netDevStatus.batteryCapacity = 85;
    netDevStatus.carAcTemp = 20;
    netDevStatus.vehInsideTemp = 23.5;
    netDevStatus.carPosition = "天津市和平区";
    netDevStatus.vehACSwitchStatus = OFF;
    netDevStatus.veHumidity = 23.5;

    mqttConnectSever(mqttHostUrl, mqttPort, mqttClientId, mqttUserName, mqttUserPasswd);
    mqttSubscribe(SubTopicName);

    connect(myClient, &QMqttClient::errorChanged, [=](QMqttClient::ClientError error)
    {
                qDebug() << error;
    });

    connect(myClient, &QMqttClient::messageReceived, this, &mqttLink::mqttReceive);
}

void mqttLink::mqttConnect()
{
    mqttConnectSever(mqttHostUrl, mqttPort, mqttClientId, mqttUserName, mqttUserPasswd);
    mqttSubscribe(SubTopicName);
}

void mqttLink::mqttConnectSever(QString hostUrl, QString Port, QString clientId, QString userName, QString userPasswd)
{
    myClient->setHostname(hostUrl);
    myClient->setPort(Port.toInt());
    myClient->setClientId(clientId);
    myClient->setUsername(userName);
    myClient->setPassword(userPasswd);
    myClient->connectToHost();
}

void mqttLink::mqttPublishTopic(QString topicName, mqttDevStatus &devStatus)
{
    QJsonObject params;
    params.insert(alyPosition, devStatus.carPosition);
    params.insert(alydoor, devStatus.carDoorStatus);
    params.insert(alyPressure, devStatus.ctirePressureStatus);
    params.insert(alyBattery, devStatus.batteryCapacity);
    params.insert(alyLock, devStatus.carLockStatus);
    params.insert(alyTrunk, devStatus.trunkStatus);
    params.insert(alyInsideTemp, devStatus.vehInsideTemp);
    params.insert(alyCarLigh, devStatus.headLightStatus);
    params.insert(alyHumidity, devStatus.veHumidity);
    params.insert(alyAcMode, devStatus.carAcModeStatus);
    params.insert(alyAcTemp, devStatus.carAcTemp);
    params.insert(alyACSwitch, devStatus.vehACSwitchStatus);

    QJsonObject data;
    data.insert("params", params);

    QJsonDocument doc(data);
    QByteArray jsonData = doc.toJson();
    // qDebug() << jsonData;

    myClient->publish(topicName, jsonData);
}

void mqttLink::mqttSubscribe(QString topicName)
{
    myClient->subscribe(topicName);
}

void mqttLink::mqttDisConnect()
{
    myClient->disconnectFromHost();
}

void mqttLink::timerTimeOut()
{
    static int flag = 0;
    if(sysDevStatus.wifiLinkStatus == true)
    {
        if(flag == 0)
        {
            mqttConnect();
        }
        flag = 1;
    }
    else
    {
        flag = 0;
    }
}

void mqttLink::mqttReceive(const QByteArray &message, const QMqttTopicName &topic)
{
    http test;
    QStringList files;
    QStringList object;
    QStringList reslutList;

    QByteArray resoureData = message;

    object << alyPosition << alydoor << alyPressure << alyBattery << alyLock << alyTrunk << alyCarLigh << alyInsideTemp << alyHumidity << alyAcMode << alyAcTemp << alyACSwitch;
    for(int i=0; i<12; i++)
    {
        files << "params" << object.at(i);
        QString rul = test.netGetJsonValue(resoureData, files, 0);
        if(rul != "xxxx")
        {
            switch(i)
            {
            case 0:
                netDevStatus.carPosition = rul;
                break;
            case 1:
                netDevStatus.carDoorStatus = (devSwitchStatus)rul.toInt();
            case 2:
                netDevStatus.ctirePressureStatus = (devSwitchStatus)rul.toInt();
            case 3:
                netDevStatus.batteryCapacity = rul.toInt();
                break;
            case 4:
                netDevStatus.carLockStatus = (devSwitchStatus)rul.toInt();
            case 5:
                netDevStatus.trunkStatus = (devSwitchStatus)rul.toInt();
                break;
            case 6:
                netDevStatus.headLightStatus = (devSwitchStatus)rul.toInt();
                break;
            case 7:
                netDevStatus.vehInsideTemp = 20.5;
                break;
            case 8:
                netDevStatus.veHumidity = 20.5;
                break;
            case 9:
                netDevStatus.carAcModeStatus = (AcMode)rul.toInt();
                break;
            case 10:
                netDevStatus.carAcTemp = rul.toFloat();
                break;
            case 11:
                netDevStatus.vehACSwitchStatus = (devSwitchStatus)rul.toInt();
                break;
            default:
                // 默认情况下的代码
                break;
            }
            mqttReceFlag = true;
            break;
        }
        files.clear();
    }
}














