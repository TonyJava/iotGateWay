#include "relay2.h"

Relay2::Relay2(QObject *parent) :
    QObject(parent)
{
}

qint8 Relay2::GetID()
{
    return 0x12;
}

void Relay2::HandleSerialMsg(const QByteArray &)
{

}

void Relay2::HandleSocketMsg(qint8 &, qint8 &)
{

}

QByteArray Relay2::GetSensorInfo()
{
    return NULL;
}
