#ifndef RFIDLOCK_H
#define RFIDLOCK_H

#include "moudle.h"

class RFIDLock : public QObject, public Moudle
{
    Q_OBJECT
public:
    explicit RFIDLock(QObject *parent = 0);
    qint8 GetID();
    void HandleSerialMsg(const QByteArray &msg);
    void HandleSocketMsg(qint8 &, qint8 &);
    QByteArray GetSensorInfo();
    
signals:
    
public slots:
    void lockdoor();

private:
    static QByteArray msg_;
    static QByteArray msglock_;
    
};

#endif // RFIDLOCK_H
