#include "pir.h"

Pir::Pir(QObject *parent) :
    QObject(parent)
{

}

qint8 Pir::GetID()
{
    return 0x05;
}

void Pir::HandleSerialMsg(const QByteArray &msg)
{
    people_status = msg[5] == 0x01?true:false;

    if(status == OPEN&&people_status)
    {
        qDebug() << "People coming in";
        SocketClass::GetInstance()->WriteToSocket(GetSensorInfo());
    }
}

void Pir::HandleSocketMsg(qint8 &, qint8 &content)
{
    status = content?OPEN:CLOSE;
}

QByteArray Pir::GetSensorInfo()
{
    return QString("0/4/3").toAscii();
}
