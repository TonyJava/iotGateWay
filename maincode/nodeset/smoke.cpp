#include "smoke.h"

Smoke::Smoke(QObject *parent) :
    QObject(parent)
{
    smoke_state_ = false;
}

qint8 Smoke::GetID()
{
    return 0x04;
}

void Smoke::HandleSerialMsg(const QByteArray &msg)
{
    if(msg[5] == 0x01)
    {
        smoke_state_ = true;
        qDebug() << "Have Smoke";
        QByteArray json_msg = GetSensorInfo();
        SocketClass::GetInstance()->WriteToSocket(json_msg);
    }
    else
    {
        if(smoke_state_)
        {
            qDebug() << "Smoke disapper";
            smoke_state_ = false;
            QByteArray json_msg = GetSensorInfo();
            SocketClass::GetInstance()->WriteToSocket(json_msg);
        }
    }
}

void Smoke::HandleSocketMsg(qint8 &, qint8 &)
{

}

QByteArray Smoke::GetSensorInfo()
{
    QString info;
    info+="0/4/";
    if(smoke_state_) info+="1";
    else info+="0";
    return info.toAscii();
}
