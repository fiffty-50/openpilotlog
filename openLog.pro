QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = openLog

RESOURCES = themes/breeze.qrc \
    themes/icons/icons.qrc \
    themes/images/images.qrc

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calc.cpp \
    dbflight.cpp \
    dbman.cpp \
    dbpilots.cpp \
    dbsettings.cpp \
    dbstat.cpp \
    easaview.cpp \
    editflight.cpp \
    homewidget.cpp \
    logbookwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    newacft.cpp \
    newflight.cpp \
    settingswidget.cpp \
    showaircraftlist.cpp \

HEADERS += \
    calc.h \
    dbflight.h \
    dbpilots.h \
    dbsettings.h \
    dbstat.h \
    easaview.h \
    editflight.h \
    homewidget.h \
    logbookwidget.h \
    mainwindow.h \
    newacft.h \
    newflight.h \
    settingswidget.h \
    showaircraftlist.h \

FORMS += \
    easaview.ui \
    editflight.ui \
    homewidget.ui \
    logbookwidget.ui \
    mainwindow.ui \
    newacft.ui \
    newflight.ui \
    settingswidget.ui \
    showaircraftlist.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Scratchpad
