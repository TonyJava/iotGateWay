#include "touch.h"

Touch::Touch(QObject *parent) :
    QObject(parent)
{
}

qint8 Touch::GetID()
{
    return 0x07;
}

void Touch::HandleSerialMsg(const QByteArray &msg)
{
    if(msg[1] != 0x07)
    {
        return;
    }

    if(msg[5] == 0x01)
    {
        touch_state_ = true;
        qDebug() << "Have Touch";
        QByteArray json_msg = GetSensorInfo();
        SocketClass::GetInstance()->WriteToSocket(json_msg);
    }
    else
    {
        if(touch_state_)
        {
            qDebug() << "Touch disapper";
            touch_state_ = false;
            QByteArray json_msg = GetSensorInfo();
            SocketClass::GetInstance()->WriteToSocket(json_msg);
        }
    }
}

void Touch::HandleSocketMsg(qint8 &, qint8 &)
{

}

QByteArray Touch::GetSensorInfo()
{
    QString info;
    info+="0/4/";
    if(touch_state_)
    {
        info+="5";
    }
    else
    {
        info+="6";
    }
    return info.toAscii();
}
