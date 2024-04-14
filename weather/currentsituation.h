#ifndef CURRENTSITUATION_H
#define CURRENTSITUATION_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtMqtt/qmqttclient.h>

// 包含生成的 UI 头文件
#include "ui_currentsituation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CurrentSituation; }
QT_END_NAMESPACE

class CurrentSituation : public QMainWindow
{
    Q_OBJECT

public:
    CurrentSituation(QWidget *parent = nullptr);
    ~CurrentSituation();

public slots:
    void setClientPort(int p);

private slots:
    void updateLogStateChange();
    void brokerDisconnected();
    void on_btn_Subscribe_clicked();
    void on_btn_Publish_clicked();
    void updateMessage(const QMqttMessage &msg);
    void updateStatus(QMqttSubscription::SubscriptionState state);


    void on_btnOpenMainWidget_clicked();

private:
    Ui::CurrentSituation *ui; // 使用生成的 UI 类
    QMqttClient *m_client = nullptr;
    QMqttSubscription *m_sub = nullptr;

    QString hostname = "iot-06z00aqr0zzjelx.mqtt.iothub.aliyuncs.com";
    QString username = "home&k0etk2XnfY8";
    QString password = "8c0514679deef58685b84715f934bbcfef3aaf78ef70d35a35d0a808b3161c15";
    QString clientid = "k0etk2XnfY8.home|securemode=2,signmethod=hmacsha256,timestamp=1711977645752|";
    int port = 1883;
    qint8 QoS = 0;
    QString default_topic = "/sys/k0etk2XnfY8/home/thing/event/property/post";
};

#endif // CURRENTSITUATION_H
