// #include "http.h"
// #include <QDebug>

// http::http(QObject *parent)
//     : QObject{parent}
// {

// }

// bool http::postSync(QString url, QMap<QString, QString> header, QByteArray resquestData, QByteArray &receiveData)
// {
//     QNetworkAccessManager manager;
//     QNetworkRequest request;

//     // 设置请求结构  url + header + body
//     request.setUrl(url);                        // 设置 url

//     QMapIterator<QString, QString> it(header);  // 设置请求头
//     while(it.hasNext())
//     {
//         it.next();
//         request.setRawHeader(it.key().toLatin1(), it.value().toLatin1());
//     }

//     // 设置 openssl 签名配置，否则 ARM 会报错
//     QSslConfiguration conf = request.sslConfiguration();
//     conf.setPeerVerifyMode(QSslSocket::VerifyNone);
// #if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
//     conf.setProtocol(QSsl::TlsV1_0);
// #else
//     conf.setProtocol(QSsl::TlsV1);
// #endif
//     request.setSslConfiguration(conf);
//     // post http 服务器
//     QNetworkReply *receive = manager.post(request, resquestData);

//     // 等待服务器回应
//     QEventLoop l;
//     connect(receive, &QNetworkReply::finished, &l, &QEventLoop::quit);
//     l.exec();

//     // 处理结果
//     if(receive != nullptr && receive->error() == QNetworkReply::NoError)
//     {
//         return true;
//     }
//     else
//     {
//         qDebug() << "Error" << receive->errorString();
//         qDebug() << "request error" << receive->errorString();
//         return false;
//     }
//     return true;
// }

// bool http::getInverseGeocoding(QString url, QString ak, QString lat, QString lon, QByteArray  &reply)
// {
//     QNetworkAccessManager manager;
//     QNetworkRequest request;
//     url=url.arg(ak).arg(lat).arg(lon);
//     //qDebug()<<url;
//     request.setUrl(url);

//     //设置openssl签名配置，否则ARM回报错
//     QSslConfiguration conf =request.sslConfiguration();
//     conf.setPeerVerifyMode(QSslSocket::VerifyNone);
// #if (QT_VERSION>QT_VERSION_CHECK(5,0,0))
//     conf.setProtocol(QSsl::TlsV1_0);
// #else
//     conf.setProtocol(QSsl::TlsV1);
// #endif
//     request.setSslConfiguration(conf);

//     QNetworkReply *receive = manager.get(request);

//     //等待服务器回应
//     QEventLoop l;
//     connect(receive,&QNetworkReply::finished,&l,&QEventLoop::quit);
//     l.exec();

//     //处理结果
//     if(receive!=nullptr && receive->error() == QNetworkReply::NoError)
//     {
//         reply=receive->readAll();
//         return true;
//     }
//     else
//     {
//         qDebug()<<"Error"<<receive->errorString();
//         qDebug()<<"request error"<<receive->errorString();
//         return false;
//     }

//     return true;
// }

// bool http::getWeather(QString url, QString ak, QString districtId, QString dataType, QByteArray &reply)
// {
//     QNetworkAccessManager manager;
//     QNetworkRequest request;
//     url = url.arg(districtId).arg(dataType).arg(ak);
//     qDebug() << url;
//     request.setUrl(url);

//     // 设置 openssl 签名配置，否则 ARM 会报错
//     QSslConfiguration conf =request.sslConfiguration();
//     conf.setPeerVerifyMode(QSslSocket::VerifyNone);
// #if (QT_VERSION>QT_VERSION_CHECK(5,0,0))
//     conf.setProtocol(QSsl::TlsV1_0);
// #else
//     conf.setProtocol(QSsl::TlsV1);
// #endif
//     request.setSslConfiguration(conf);

//     QNetworkReply *receive = manager.get(request);

//     //等待服务器回应
//     QEventLoop l;
//     connect(receive,&QNetworkReply::finished,&l,&QEventLoop::quit);
//     l.exec();

//     //处理结果
//     if(receive!=nullptr && receive->error() == QNetworkReply::NoError)
//     {
//         reply=receive->readAll();
//         return true;
//     }
//     else
//     {
//         qDebug()<<"Error"<<receive->errorString();
//         qDebug()<<"request error"<<receive->errorString();
//         return false;
//     }
// }

// QString http::netGetJsonValue(QByteArray resoureData, QStringList key, int arrIndex)
// {
//     int i = 0;
//     QJsonParseError parseError;
//     QJsonDocument jsonDocument = QJsonDocument::fromJson(resoureData, &parseError);
//     qDebug() << jsonDocument;
//     if(parseError.error == QJsonParseError::NoError)
//     {
//         if(jsonDocument.isObject())
//         {
//             QJsonObject jsonObject = jsonDocument.object();
//             if(jsonObject.contains(key.at(i)))
//             {
//                 QJsonValue jsonValue = jsonObject.value(key.at(i));

//                 while(jsonValue.isObject())
//                 {
//                     i++;
//                     jsonObject = jsonValue.toObject();
//                     if(jsonObject.contains(key.at(i)))
//                     {
//                         jsonValue = jsonObject.value(key.at(i));
//                     }
//                     else
//                     {
//                         break;
//                     }
//                 }
//                 if(jsonValue.isString())
//                 {
//                     return jsonValue.toString();
//                 }
//                 else if(jsonValue.isDouble())
//                 {
//                     return QString::number(jsonValue.toDouble());
//                 }
//                 else if(jsonValue.isArray())
//                 {
//                     QJsonArray arr = jsonValue.toArray();
//                     QJsonValue val = arr.at(arrIndex);

//                     jsonObject = val.toObject();
//                     if(jsonObject.contains(key.at(i+1)))
//                     {
//                         jsonValue = jsonObject.value(key.at(i+1));
//                     }

//                     if(jsonValue.isString())
//                     {
//                         return jsonValue.toString();
//                     }
//                     else if(jsonValue.isDouble())
//                     {
//                         return QString::number(jsonValue.toDouble());
//                     }
//                 }
//             }
//         }
//     }
//     return "xxxx";
// }



#include "http.h"
#include <QDebug>
http::http(QObject *parent)
    : QObject{parent}
{

}

bool http::postSync(QString url, QMap<QString, QString> header, QByteArray resqustData, QByteArray &receiveData)
{
    QNetworkAccessManager manager;
    QNetworkRequest request;

    //设置请求结构 url+header + body
    request.setUrl(url);//setting url

    QMapIterator<QString,QString> it(header);//setting header
    while(it.hasNext())
    {
        it.next();
        request.setRawHeader(it.key().toLatin1(),it.value().toLatin1());
    }

    //设置openssl签名配置，否则ARM回报错
    QSslConfiguration conf =request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
#if (QT_VERSION>QT_VERSION_CHECK(5,0,0))
    conf.setProtocol(QSsl::TlsV1_0);
#else
    conf.setProtocol(QSsl::TlsV1);
#endif
    request.setSslConfiguration(conf);
    //post http服务器
    QNetworkReply *receive=manager.post(request,resqustData);

    //等待服务器回应
    QEventLoop l;
    connect(receive,&QNetworkReply::finished,&l,&QEventLoop::quit);
    l.exec();

    //处理结果
    if(receive!=nullptr && receive->error() == QNetworkReply::NoError)
    {
        receiveData=receive->readAll();
        return true;
    }
    else
    {
        qDebug()<<"Error"<<receive->errorString();
        qDebug()<<"request error"<<receive->errorString();
        return false;
    }
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
    url=url.arg(districtId).arg(dataType).arg(ak);
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

}

QString http::netGetJsonValue(QByteArray resoureData, QStringList key,int arrIndex)
{
    int i=0;
    QJsonParseError parseError;
    QJsonDocument jsonDocument=QJsonDocument::fromJson(resoureData,&parseError);
    //qDebug()<<jsonDocument;
    if(parseError.error == QJsonParseError::NoError)
    {
        // qDebug()<<"jsonDocument";
        if(jsonDocument.isObject())//查看对象是否存在
        {
            //qDebug()<<"isObject";
            QJsonObject jsonObject=jsonDocument.object();//获取对象
            if(jsonObject.contains(key.at(i)))//查看对应键值是否存在
            {
                //qDebug()<<"key";
                QJsonValue jsonValue = jsonObject.value(key.at(i));//获取键值对应的值
                //qDebug()<<jsonValue;
                while(jsonValue.isObject())
                {
                    i++;
                    //qDebug()<<"key";
                    jsonObject=jsonValue.toObject();
                    // qDebug()<<jsonObject;
                    if(jsonObject.contains(key.at(i)))//查看对应键值是否存在
                    {
                        jsonValue = jsonObject.value(key.at(i));//获取键值对应的值
                        // qDebug()<<jsonValue;
                    }
                    else
                    {
                        break;
                    }
                }

                if(jsonValue.isString())
                {
                    return jsonValue.toString();
                }//判断是否为对象
                else if(jsonValue.isDouble())//判断是否为数值
                {
                    return QString::number(jsonValue.toDouble());
                }
                else if(jsonValue.isArray())//判断是否为数组
                {
                    QJsonArray arr = jsonValue.toArray();//获取数组里的所有成员对象
                    QJsonValue val = arr.at(arrIndex);//剥离

                    jsonObject=val.toObject();//获取最后一层的对象
                    if(jsonObject.contains(key.at(i+1)))//查看对应键值是否存在
                    {
                        jsonValue = jsonObject.value(key.at(i+1));//获取键值对应的值
                        //qDebug()<<jsonValue;
                    }

                    if(jsonValue.isString())
                    {
                        return jsonValue.toString();
                    }//判断是否为对象
                    else if(jsonValue.isDouble())//判断是否为数值
                    {
                        return QString::number(jsonValue.toDouble());
                    }
                }

            }
        }
    }
    return "xxxx";
}


















