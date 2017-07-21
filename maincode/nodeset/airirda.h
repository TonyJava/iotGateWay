#ifndef AIRIRDA_H
#define AIRIRDA_H

#include "moudle.h"

class AirIrda : public QObject, public Moudle
{
    Q_OBJECT
public:
    explicit AirIrda(QObject *parent = 0);
    qint8 GetID();
    void HandleSerialMsg(const QByteArray &);
    void HandleSocketMsg(qint8 &cmd, qint8 &content);
    QByteArray GetSensorInfo();
    
signals:
    
public slots:

private:
    static QByteArray msg_;
    static qint8 current_temp_;
    
};

#endif // AIRIRDA_H
