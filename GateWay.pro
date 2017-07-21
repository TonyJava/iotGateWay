#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T22:16:57
#
#-------------------------------------------------

QT       += core gui network sql

TARGET = GateWay
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    port/posix_qextserialport.cpp \
    port/qextserialbase.cpp \
    port/qextserialport.cpp \
    service/serialclass.cpp \
    service/socketclass.cpp \
    maincode/nodeset/airirda.cpp \
    maincode/nodeset/curtain.cpp \
    maincode/nodeset/moudle.cpp \
    maincode/nodeset/pir.cpp \
    maincode/nodeset/relay.cpp \
    maincode/nodeset/relay2.cpp \
    maincode/nodeset/rfidlock.cpp \
    maincode/nodeset/smoke.cpp \
    maincode/nodeset/temperature.cpp \
    maincode/nodeset/touch.cpp \
    maincode/moudleset.cpp

HEADERS  += widget.h \
    port/posix_qextserialport.h \
    port/qextserialbase.h \
    port/qextserialport.h \
    service/serialclass.h \
    service/socketclass.h \
    maincode/nodeset/airirda.h \
    maincode/nodeset/curtain.h \
    maincode/nodeset/moudle.h \
    maincode/nodeset/pir.h \
    maincode/nodeset/relay.h \
    maincode/nodeset/relay2.h \
    maincode/nodeset/rfidlock.h \
    maincode/nodeset/smoke.h \
    maincode/nodeset/temperature.h \
    maincode/nodeset/touch.h \
    maincode/moudleset.h

FORMS    += widget.ui

unix:DEFINES           += _TTY_POSIX_
