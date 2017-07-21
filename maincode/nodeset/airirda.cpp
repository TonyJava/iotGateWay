#include "airirda.h"

AirIrda::AirIrda(QObject *parent) :
    QObject(parent)
{
}

QByteArray AirIrda::msg_("\x40\x07\x01\x0f\x00\x00\x00", 7);
qint8 AirIrda::current_temp_(0x16);

qint8 AirIrda::GetID()
{
    return 0x0f;
}

void AirIrda::HandleSerialMsg(const QByteArray &)
{

}

void AirIrda::HandleSocketMsg(qint8 &cmd, qint8 &content)
{
    if(cmd<1 || cmd >9)
    {
        return;
    }

    msg_[4] = cmd;
    if(cmd == 0x06)
    {
        if(content) current_temp_++;
        else current_temp_--;
        if(current_temp_ > 0x1e) current_temp_ = 0x1e;
        if(current_temp_ < 0x10) current_temp_ = 0x10;
        msg_[5] = current_temp_;
    }
    else if(cmd == 0x04)
    {
        if(content) msg_[5] = 0xff;
        else msg_[5] = 0x00;
    }
    else
    {
        msg_[5] = content;
    }

    unsigned char var;
    char *str;
    str = msg_.data();
    qDebug()<< "Air : " << msg_.toHex();
    var = Moudle::Varify((unsigned char *)str, 6);
    msg_[6] = var;
    SerialClass::GetInstance()->WriteToSerial(msg_);
}

QByteArray AirIrda::GetSensorInfo()
{
    return NULL;
}
