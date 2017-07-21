#ifndef RELAY_H
#define RELAY_H

#include "moudle.h"

class Relay : public QObject, public Moudle
{
    Q_OBJECT
public:
    explicit Relay(QObject *parent = 0);
    qint8 GetID();
    void HandleSerialMsg(const QByteArray &);
    void HandleSocketMsg(qint8 &cmd, qint8 &content);
    QByteArray GetSensorInfo();

signals:
    
public slots:

private:
    static QByteArray msg_;
    
};

#endif // RELAY_H
