#ifndef SMOKE_H
#define SMOKE_H

#include "moudle.h"

class Smoke : public QObject, public Moudle
{
    Q_OBJECT
public:
    explicit Smoke(QObject *parent = 0);
    qint8 GetID();
    void HandleSerialMsg(const QByteArray &msg);
    void HandleSocketMsg(qint8 &, qint8 &);
    QByteArray GetSensorInfo();
    
signals:
    
public slots:

private:
    bool smoke_state_;
    
};

#endif // SMOKE_H
