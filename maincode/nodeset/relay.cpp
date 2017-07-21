#include "relay.h"

Relay::Relay(QObject *parent) :
    QObject(parent)
{
}

QByteArray Relay::msg_("\x40\x07\x01\x0a\x00\x00\xFF", 7);

qint8 Relay::GetID()
{
    return 0x0a;
}

void Relay::HandleSerialMsg(const QByteArray &)
{

}

void Relay::HandleSocketMsg(qint8 &cmd, qint8 &content)
{
    if (1 > cmd || 5 < cmd)
    {
        return ;
    }
    if(!(content == 0||content == 1)) return;

    if(cmd == 0x01)
    {
        msg_[4] = 0x08;
        if(content)
        {
            msg_[5] = 0x08;
        }
        else
        {
            msg_[5] = 0x00;
        }
    }
    else if(cmd == 0x02)
    {
        msg_[4] = 0x04;
        if(content)
        {
            msg_[5] = 0x04;
        }
        else
        {
            msg_[5] = 0x00;
        }
    }
    else if(cmd == 0x03)
    {
        msg_[4] = 0x02;
        if(content)
        {
            msg_[5] = 0x02;
        }
        else
        {
            msg_[5] = 0x00;
        }
    }
    else if(cmd == 0x04)
    {
        msg_[4] = 0x01;
        if(content)
        {
            msg_[5] = 0x01;
        }
        else
        {
            msg_[5] = 0x00;
        }
    }
    unsigned char var;
    char *str;
    str = msg_.data();
    var = Moudle::Varify((unsigned char*)str,6);
    msg_[6] = var;
    SerialClass::GetInstance()->WriteToSerial(msg_);
    SerialClass::GetInstance()->WriteToSerial(msg_);
    qDebug() << cmd << content << "===";
}

QByteArray Relay::GetSensorInfo()
{
    return NULL;
}
