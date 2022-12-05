#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer serialport
QT       +=network
QT       +=svg
QT       +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestion_bagage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
QMAKE_CXXFLAGS+= -std=gnu++14

SOURCES += \
    arduino.cpp \
    avion.cpp \
    avions.cpp \
    bagages.cpp \
    billet.cpp \
    camera.cpp \
    employee.cpp \
    employer.cpp \
    excel.cpp \
    gestion_passager.cpp \
    gestion_vol.cpp \
    gpsvalise.cpp \
    login.cpp \
        main.cpp \
    connection.cpp \
    mainwindow_Bagage.cpp \
    mainwindowayoub.cpp \
    menu.cpp \
    passager.cpp \
    pdf.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    smtp.cpp \
    stat_combo.cpp \
    vol.cpp

HEADERS += \
    arduino.h \
    avion.h \
    avions.h \
    bagages.h \
    billet.h \
    camera.h \
    employee.h \
    employer.h \
    excel.h \
    gestion_passager.h \
    gestion_vol.h \
    gpsvalise.h \
    login.h \
    connection.h \
    mainwindow_Bagage.h \
    mainwindowayoub.h \
    menu.h \
    passager.h \
    pdf.h \
    qcustomplot.h \
    qrcode.h \
    smtp.h \
    stat.h \
    stat_combo.h \
    vol.h \
    webaxwidget.h

FORMS += \
        avions.ui \
        camera.ui \
        employer.ui \
        login.ui \
        mainwindow_Bagage.ui \
        mainwindowayoub.ui \
        menu.ui \
        passager.ui \
        pdf.ui \
        stat_combo.ui \
        vol.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

