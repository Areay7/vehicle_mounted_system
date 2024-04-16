#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

class http : public QObject
{
    Q_OBJECT
public:
    explicit http(QObject *parent = nullptr);
    bool postSync(QString url, QMap<QString, QString>header, QByteArray resquestData, QByteArray &receiveData);
    bool getInverseGeocoding(QString url, QString ak, QString lat, QString lon, QByteArray &reply);
    bool getWeather(QString url, QString ak, QString districtId, QString dataType, QByteArray &reply);
    QString netGetJsonValue(QByteArray resoureData, QStringList key, int arrIndex);
signals:

};

#endif // HTTP_H
