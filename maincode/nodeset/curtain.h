#ifndef CURTAIN_H
#define CURTAIN_H

#include "moudle.h"

class Curtain : public QObject, public Moudle
{
    Q_OBJECT
public:
    explicit Curtain(QObject *parent = 0);
    qint8 GetID();
    void HandleSerialMsg(const QByteArray &);
    void HandleSocketMsg(qint8 &, qint8 &content);
    QByteArray GetSensorInfo();

signals:
    
public slots:

private:
    static QByteArray msg_;
    
};

#endif // CURTAIN_H
