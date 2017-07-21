#include "rfidlock.h"

RFIDLock::RFIDLock(QObject *parent) :
    QObject(parent)
{
}

QByteArray RFIDLock::msg_("\x40\x07\x01\x12\x01\x00\xff", 7);
QByteArray RFIDLock::msglock_("\x40\x07\x01\x12\x01\x01\xff", 7);

qint8 RFIDLock::GetID()
{
    return 0x15;
}

void RFIDLock::HandleSerialMsg(const QByteArray &msg)
{
    QString user= QString(msg.toHex()).mid(10,8);
    qDebug()<<"RFID is:"+user;
    if(user == "4aacbfd5")
    {
        qDebug() << "Open door via zigbee";
        unsigned char var;
        char *str;
        str = msg_.data();
        var = Moudle::Varify((unsigned char *)str, 6);
        msg_[6] = var;
        SerialClass::GetInstance()->WriteToSerial(msg_);
        SerialClass::GetInstance()->WriteToSerial(msg_);

        QTimer *timer = new QTimer();
        timer->setSingleShot(true);
        connect( timer, SIGNAL(timeout()), this, SLOT(lockdoor()) );
        timer->start(2000);
    }
}

void RFIDLock::HandleSocketMsg(qint8 &, qint8 &)
{
    qDebug() << "Open door via Socket";
    unsigned char var;
    char *str;
    str = msg_.data();
    var = Moudle::Varify((unsigned char *)str, 6);
    msg_[6] = var;
    SerialClass::GetInstance()->WriteToSerial(msg_);
    SerialClass::GetInstance()->WriteToSerial(msg_);

    QTimer *timer = new QTimer();
    timer->setSingleShot(true);
    connect( timer, SIGNAL(timeout()), this, SLOT(lockdoor()) );
    timer->start(2000);
}

QByteArray RFIDLock::GetSensorInfo()
{
    return NULL;
}

void RFIDLock::lockdoor()
{
    unsigned char var;
    char *str;
    str = msglock_.data();
    var = Moudle::Varify((unsigned char *)str, 6);
    msglock_[6] = var;
    SerialClass::GetInstance()->WriteToSerial(msglock_);
    SerialClass::GetInstance()->WriteToSerial(msglock_);
}
