#ifndef SPECCH_H
#define SPECCH_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QMap>
#include "http.h"
#include <QHostInfo>

const QString baiduTokenUrl = "http://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=%1&client_secret=%2&";
const QString client_id = "GrQqm4aPwUfOwg7XtqadlEOC";
const QString client_secret = "emulcTYiejkkE4V27XMq5oEEI3hodD32";
//    语音识别url
const QString baiduSpeechUrl = "http://vop.baidu.com/server_api?dev_pid=1537&cuid=%1&token=%2&";

class specch : public QObject
{
    Q_OBJECT
public:
    explicit specch(QObject *parent = nullptr);
    QString getJsonValue(QByteArray resoureData,QString key);
    QString speechIdentify(QString fileName);

signals:

private:

};

#endif // SPECCH_H
