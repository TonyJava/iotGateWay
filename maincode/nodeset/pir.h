#ifndef PIR_H
#define PIR_H

#include "moudle.h"

class Pir : public QObject, public Moudle
{
    Q_OBJECT
public:
    explicit Pir(QObject *parent = 0);
    qint8 GetID();
    void HandleSerialMsg(const QByteArray &msg);
    void HandleSocketMsg(qint8 &, qint8 &content);
    QByteArray GetSensorInfo();
    
signals:
    
public slots:

private:
    enum{OPEN, CLOSE}status;
    bool people_status;
    
};

#endif // PIR_H
