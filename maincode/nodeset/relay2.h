#ifndef RELAY2_H
#define RELAY2_H

#include "moudle.h"

class Relay2 : public QObject, public Moudle
{
    Q_OBJECT
public:
    explicit Relay2(QObject *parent = 0);
    qint8 GetID();
    void HandleSerialMsg(const QByteArray &);
    void HandleSocketMsg(qint8 &, qint8 &);
    QByteArray GetSensorInfo();

signals:
    
public slots:
    
};

#endif // RELAY2_H
