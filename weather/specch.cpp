#include "specch.h"

specch::specch(QObject *parent)
    : QObject{parent}
{

}



QString specch::speechIdentify(QString fileName)
{
    QString tokenUrl=QString(baiduTokenUrl).arg(client_id).arg(client_secret);
    QMap<QString,QString> header;

    QByteArray resqustData;
    QByteArray receiveData;
    http myHttp;

    header.insert(QString("Content-Type"),QString("audio/pcm;rate=16000"));
    //获取 access_token
    bool result=myHttp.postSync(tokenUrl,header,resqustData,receiveData);

    if(result)
    {
        // refresh_token
        QString key = "access_token";
        QString accessToken=getJsonValue(receiveData,key);
        qDebug()<<"accessToken"<<accessToken;

        QString speechUrl=QString(baiduSpeechUrl).arg(QHostInfo::localHostName()).arg(accessToken);

        //加载wav文件
        QFile file;
        qDebug()<<"baiduspeechUrl:"<<speechUrl;
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);
        resqustData=file.readAll();
        file.close();

        receiveData.clear();
        //获取 wav转文本
        result=myHttp.postSync(speechUrl,header,resqustData,receiveData);
        if(result)
        {
            QString key = "result";
            QString retText = getJsonValue(receiveData,key);
            qDebug()<<"retText:"<<retText;
            return retText;
        }
        else
        {
            return nullptr;
        }
    }

    return "";
}

QString specch::getJsonValue(QByteArray resoureData, QString key)
{
    QJsonParseError parseError;
    QJsonDocument jsonDocument=QJsonDocument::fromJson(resoureData,&parseError);
    if(parseError.error == QJsonParseError::NoError)
    {
        if(jsonDocument.isObject())//查看对象是否存在
        {
            QJsonObject jsonObject=jsonDocument.object();//获取对象
            if(jsonObject.contains(key))//查看对应键值是否存在
            {
                QJsonValue jsonValue = jsonObject.value(key);//获取键值对应的值
                if(jsonValue.isString())//判断是否为对象
                    return jsonValue.toString();
                else if(jsonValue.isArray())//判断是否为数组
                {
                    QJsonArray arr = jsonValue.toArray();
                    QJsonValue val = arr.at(0);//剥离
                    return val.toString();
                }
            }
        }
    }
    return "";
}
