#include "http.h"
#include <QDebug>

http::http(QObject *parent)
    : QObject{parent}
{

}

bool http::postSync(QString url, QMap<QString, QString> header, QByteArray resquestData, QByteArray &receiveData)
{
    QNetworkAccessManager manager;
    QNetworkRequest request;

    // 设置请求结构  url + header + body
    request.setUrl(url);                        // 设置 url

    QMapIterator<QString, QString> it(header);  // 设置请求头
    while(it.hasNext())
    {
        it.next();
        request.setRawHeader(it.key().toLatin1(), it.value().toLatin1());
    }

    // 设置 openssl 签名配置，否则 ARM 会报错
    QSslConfiguration conf = request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
    conf.setProtocol(QSsl::TlsV1_0);
#else
    conf.setProtocol(QSsl::TlsV1);
#endif
    request.setSslConfiguration(conf);
    // post http 服务器
    QNetworkReply *receive = manager.post(request, resquestData);

    // 等待服务器回应
    QEventLoop l;
    connect(receive, &QNetworkReply::finished, &l, &QEventLoop::quit);
    l.exec();

    // 处理结果
    if(receive != nullptr && receive->error() == QNetworkReply::NoError)
    {
        return true;
    }
    else
    {
        qDebug() << "Error" << receive->errorString();
        qDebug() << "request error" << receive->errorString();
        return false;
    }
    return true;
}

bool http::getInverseGeocoding(QString url, QString ak, QString lat, QString lon, QByteArray  &reply)
{
    QNetworkAccessManager manager;
    QNetworkRequest request;
    url=url.arg(ak).arg(lat).arg(lon);
    //qDebug()<<url;
    request.setUrl(url);

    //设置openssl签名配置，否则ARM回报错
    QSslConfiguration conf =request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
#if (QT_VERSION>QT_VERSION_CHECK(5,0,0))
    conf.setProtocol(QSsl::TlsV1_0);
#else
    conf.setProtocol(QSsl::TlsV1);
#endif
    request.setSslConfiguration(conf);

    QNetworkReply *receive = manager.get(request);

    //等待服务器回应
    QEventLoop l;
    connect(receive,&QNetworkReply::finished,&l,&QEventLoop::quit);
    l.exec();

    //处理结果
    if(receive!=nullptr && receive->error() == QNetworkReply::NoError)
    {
        reply=receive->readAll();
        return true;
    }
    else
    {
        qDebug()<<"Error"<<receive->errorString();
        qDebug()<<"request error"<<receive->errorString();
        return false;
    }

    return true;
}

bool http::getWeather(QString url, QString ak, QString districtId, QString dataType, QByteArray &reply)
{
    QNetworkAccessManager manager;
    QNetworkRequest request;
    url = url.arg(districtId).arg(dataType).arg(ak);
    qDebug() << url;
    request.setUrl(url);

    // 设置 openssl 签名配置，否则 ARM 会报错
    QSslConfiguration conf =request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
#if (QT_VERSION>QT_VERSION_CHECK(5,0,0))
    conf.setProtocol(QSsl::TlsV1_0);
#else
    conf.setProtocol(QSsl::TlsV1);
#endif
    request.setSslConfiguration(conf);

    QNetworkReply *receive = manager.get(request);

    //等待服务器回应
    QEventLoop l;
    connect(receive,&QNetworkReply::finished,&l,&QEventLoop::quit);
    l.exec();

    //处理结果
    if(receive!=nullptr && receive->error() == QNetworkReply::NoError)
    {
        reply=receive->readAll();
        return true;
    }
    else
    {
        qDebug()<<"Error"<<receive->errorString();
        qDebug()<<"request error"<<receive->errorString();
        return false;
    }
}

QString http::netGetJsonValue(QByteArray resoureData, QStringList key, int arrIndex)
{
    int i = 0;
    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(resoureData, &parseError);
    qDebug() << jsonDocument;
    if(parseError.error == QJsonParseError::NoError)
    {
        if(jsonDocument.isObject())
        {
            QJsonObject jsonObject = jsonDocument.object();
            if(jsonObject.contains(key.at(i)))
            {
                QJsonValue jsonValue = jsonObject.value(key.at(i));

                while(jsonValue.isObject())
                {
                    i++;
                    jsonObject = jsonValue.toObject();
                    if(jsonObject.contains(key.at(i)))
                    {
                        jsonValue = jsonObject.value(key.at(i));
                    }
                    else
                    {
                        break;
                    }
                }
                if(jsonValue.isString())
                {
                    return jsonValue.toString();
                }
                else if(jsonValue.isDouble())
                {
                    return QString::number(jsonValue.toDouble());
                }
                else if(jsonValue.isArray())
                {
                    QJsonArray arr = jsonValue.toArray();
                    QJsonValue val = arr.at(arrIndex);

                    jsonObject = val.toObject();
                    if(jsonObject.contains(key.at(i+1)))
                    {
                        jsonValue = jsonObject.value(key.at(i+1));
                    }

                    if(jsonValue.isString())
                    {
                        return jsonValue.toString();
                    }
                    else if(jsonValue.isDouble())
                    {
                        return QString::number(jsonValue.toDouble());
                    }
                }
            }
        }
    }
    return "xxxx";
}



















