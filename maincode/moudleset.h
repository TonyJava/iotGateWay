#ifndef MOUDLESET_H
#define MOUDLESET_H

#include <QObject>
#include <QTimer>
#include <QHash>
#include "../service/serialclass.h"
#include "../service/socketclass.h"
#include "nodeset/moudle.h"
#include "nodeset/temperature.h"
#include "nodeset/smoke.h"
#include "nodeset/pir.h"
#include "nodeset/touch.h"
#include "nodeset/relay.h"
#include "nodeset/airirda.h"
#include "nodeset/curtain.h"
#include "nodeset/rfidlock.h"
#include "nodeset/relay2.h"

class MoudleSet : public QObject
{
    Q_OBJECT
public:
    explicit MoudleSet(QObject *parent = 0);
    void InitMoudle();
    
signals:
    
public slots:
    void ReadSerial(QByteArray byte);
    void ReadSocket(QByteArray byte);
    void loginverify();

private:
    SerialClass *serial_service_;
    SocketClass *socket_serivce_;
    Moudle* temp_moudle_;
    Moudle* smoke_moudle_;
    Moudle* pir_moudle_;
    Moudle* touch_moudle_;
    Moudle* relay1_moudle_;
    Moudle* irda_moudle_;
    Moudle* curtain_moudle_;
    Moudle* relay2_moudle_;
    Moudle* rfid_moudle_;

    QHash<qint8, Moudle*> moudle_hash_;
    
};

#endif // MOUDLESET_H
