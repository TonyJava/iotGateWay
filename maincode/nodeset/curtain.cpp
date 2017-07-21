#include "curtain.h"

Curtain::Curtain(QObject *parent) :
    QObject(parent)
{
}

QByteArray Curtain::msg_("\x40\x07\x01\x10\x01\x01\x00", 7);

qint8 Curtain::GetID()
{
    return 0x10;
}

void Curtain::HandleSerialMsg(const QByteArray &)
{

}

void Curtain::HandleSocketMsg(qint8 &, qint8 &content)
{
    msg_[4] = content==0x01?0x01:0x00;

    unsigned char var;
    char *str;
    str = msg_.data();
    var = Moudle::Varify((unsigned char *)str, 6);
    msg_[6] = var;
    qDebug() << "Curtain : " << msg_;
    SerialClass::GetInstance()->WriteToSerial(msg_);
}

QByteArray Curtain::GetSensorInfo()
{
    return NULL;
}
