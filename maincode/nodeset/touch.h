#ifndef TOUCH_H
#define TOUCH_H

#include "moudle.h"

class Touch : public QObject, public Moudle
{
    Q_OBJECT
public:
    explicit Touch(QObject *parent = 0);
    qint8 GetID();
    void HandleSerialMsg(const QByteArray &msg);
    void HandleSocketMsg(qint8 &, qint8 &);
    QByteArray GetSensorInfo();
    
signals:
    
public slots:

private:
    bool touch_state_;
    
};

#endif // TOUCH_H
