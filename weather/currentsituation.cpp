#include <QtCore/QDateTime>
#include <QtMqtt/qmqttclient.h>
#include <QtWidgets/QMessageBox>
#include "currentsituation.h"
#include "ui_currentsituation.h" // 手动包含 UI 头文件
#include "mainwidget.h"


CurrentSituation::CurrentSituation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CurrentSituation) // 初始化 UI 对象
{
    ui->setupUi(this); // 使用 UI 对象进行初始化

    m_client = new QMqttClient(this);

    connect(m_client, &QMqttClient::stateChanged, this, &CurrentSituation::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &CurrentSituation::brokerDisconnected);

    connect(m_client, &QMqttClient::messageReceived, this, [](const QByteArray &message, const QMqttTopicName &topic) {
        const QString content = QDateTime::currentDateTime().toString()
                                + QLatin1String(" Received Topic: ")
                                + topic.name()
                                + QLatin1String(" Message: ")
                                + message
                                + QLatin1Char('\n');
        // ui->editLog->insertPlainText(content);
    });

    connect(m_client, &QMqttClient::pingResponseReceived, this, []() {
        const QString content = QDateTime::currentDateTime().toString()
                                + QLatin1String(" PingResponse")
                                + QLatin1Char('\n');
        //  ui->editLog->insertPlainText(content);
    });

    connect(m_client, &QMqttClient::connected, this, [this]() {
        ui->label_MqttState->setText(tr("MQTT 服务连接成功！"));
    });

    setClientPort(port);
    m_client->setHostname(hostname);
    m_client->setUsername(username);
    m_client->setPassword(password);
    m_client->setClientId(clientid);
    m_client->connectToHost();
    updateLogStateChange();
}

CurrentSituation::~CurrentSituation()
{
    delete ui;
    qApp->quit();
    if(m_sub!=nullptr){
        delete m_sub;
    }
}

void CurrentSituation::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                            + QLatin1String(": State Change")
                            + QString::number(m_client->state())
                            + QLatin1Char('\n');
    //ui->editLog->insertPlainText(content);
}

void CurrentSituation::brokerDisconnected()
{
    ui->label_MqttState->setText(tr("连接失败！"));
}

void CurrentSituation::setClientPort(int p)
{
    m_client->setPort(p);
}

void CurrentSituation::on_btn_Subscribe_clicked()
{
    QMqttSubscription* subscription = m_client->subscribe(default_topic, QoS);
    if (!subscription) {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    } else {
        m_sub = subscription;
        updateStatus(m_sub->state());
        ui->label_topic->setText(m_sub->topic().filter());
        connect(m_sub, &QMqttSubscription::messageReceived, this, &CurrentSituation::updateMessage);
        connect(m_sub, &QMqttSubscription::stateChanged, this, &CurrentSituation::updateStatus);
        connect(m_sub, &QMqttSubscription::qosChanged, [this](quint8 qos) {
            ui->label_QoS->setText(QString::number(qos));
        });
    }
}

void CurrentSituation::updateMessage(const QMqttMessage &msg)
{
    ui->label_payload->setText(msg.payload());
}

void CurrentSituation::updateStatus(QMqttSubscription::SubscriptionState state)
{
    switch (state) {
    case QMqttSubscription::Unsubscribed:
        ui->label_subscribr_status->setText(QLatin1String("Unsubscribed"));
        break;
    case QMqttSubscription::SubscriptionPending:
        ui->label_subscribr_status->setText(QLatin1String("Pending"));
        break;
    case QMqttSubscription::Subscribed:
        ui->label_subscribr_status->setText(tr("订阅主题成功"));
        break;
    case QMqttSubscription::Error:
        ui->label_subscribr_status->setText(QLatin1String("Error"));
        break;
    default:
        ui->label_subscribr_status->setText(QLatin1String("--Unknown--"));
        break;
    }
}

void CurrentSituation::on_btn_Publish_clicked()
{
    QString jsonMessage = ui->line_payload->text();
    QMqttTopicName topicName(ui->line_pubtopic->text());
    m_client->publish(topicName, jsonMessage.toUtf8());
}

void CurrentSituation::on_btnOpenMainWidget_clicked()
{
    // 隐藏当前窗口
    this->hide();

    // 创建主窗口实例
    MainWidget *mainWidget = new MainWidget();

    // 显示主窗口
    mainWidget->show();
}

