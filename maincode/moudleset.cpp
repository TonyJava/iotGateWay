#include "moudleset.h"

MoudleSet::MoudleSet(QObject *parent) :
    QObject(parent)
{
}

void MoudleSet::InitMoudle()
{
    serial_service_ = SerialClass::GetInstance();
    socket_serivce_ = SocketClass::GetInstance();
    connect(this->serial_service_,SIGNAL(SerialMsg(QByteArray)),this,SLOT(ReadSerial(QByteArray)));
    connect(this->socket_serivce_,SIGNAL(SocketMsg(QByteArray)),this,SLOT(ReadSocket(QByteArray)));
    connect(this->socket_serivce_,SIGNAL(Connection()),this,SLOT(loginverify()));

    temp_moudle_   = new Temperature();
    smoke_moudle_  = new Smoke();
    pir_moudle_    = new Pir();
    touch_moudle_  = new Touch();
    relay1_moudle_ = new Relay();
    irda_moudle_   = new AirIrda();
    curtain_moudle_= new Curtain();
    relay2_moudle_ = new Relay2();
    rfid_moudle_   = new RFIDLock();

    moudle_hash_.insert(0x02,temp_moudle_);
    moudle_hash_.insert(0x04,smoke_moudle_);
    moudle_hash_.insert(0x05,pir_moudle_);
    moudle_hash_.insert(0x07,touch_moudle_);
    moudle_hash_.insert(0x0a,relay1_moudle_);
    moudle_hash_.insert(0x0f,irda_moudle_);
    moudle_hash_.insert(0x10,curtain_moudle_);
    moudle_hash_.insert(0x12,relay2_moudle_);
    moudle_hash_.insert(0x15,rfid_moudle_);
}

void MoudleSet::ReadSerial(QByteArray byte)
{
    qint8 node = byte[3];
    qDebug() << "Node ID : 0x"+QString::number(node,16);
    if(node == 0)
        return;
    Moudle* temp = moudle_hash_.value(node,NULL);
    if(NULL != temp)
        temp->HandleSerialMsg(byte);
    else
        qDebug() << "Error Occur on serial: Node is " << node;
}

void MoudleSet::ReadSocket(QByteArray byte)
{
    qDebug() << "Receive Form Server : " << byte.toHex();
    char *b = byte.data();
    qint8 node = b[0];
    if(node == 0x41 || node == 0x40)//signin and signup
    {
        return;
    }
    else if(node >= 0x20 && node <=0x22)//relate to movie
    {

    }
    else if(node >= 0x30 && node <= 0x32)//relate to download movie by gateway
    {

    }
    else
    {
        Moudle* temp = moudle_hash_.value(node,NULL);
        if(NULL != temp)
        {
            qint8 m1 = b[1];
            qint8 m2 = b[2];
            temp->HandleSocketMsg(m1, m2);
        }
        else
            qDebug() << "Error Occur on socket: Node is " << node;
    }
}

void MoudleSet::loginverify()
{
    socket_serivce_->WriteToSocket("0/0/ihome_001/123");
}

