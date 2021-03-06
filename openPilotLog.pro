QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

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
    main.cpp \
    mainwindow.cpp \
    src/classes/aircraft.cpp \
    src/classes/calc.cpp \
    src/classes/completionlist.cpp \
    src/classes/flight.cpp \
    src/classes/pilot.cpp \
    src/classes/runguard.cpp \
    src/classes/settings.cpp \
    src/classes/stat.cpp \
    src/classes/strictrxvalidator.cpp \
    src/database/db.cpp \
    src/database/dbinfo.cpp \
    src/database/entry.cpp \
    src/gui/dialogues/firstrundialog.cpp \
    src/gui/dialogues/newflightdialog.cpp \
    src/gui/dialogues/newpilotdialog.cpp \
    src/gui/dialogues/newtaildialog.cpp \
    src/gui/widgets/aircraftwidget.cpp \
    src/gui/widgets/homewidget.cpp \
    src/gui/widgets/logbookwidget.cpp \
    src/gui/widgets/pilotswidget.cpp \
    src/gui/widgets/settingswidget.cpp \
    src/gui/widgets/totalswidget.cpp

HEADERS += \
    mainwindow.h \
    src/classes/aircraft.h \
    src/classes/calc.h \
    src/classes/completionlist.h \
    src/classes/flight.h \
    src/classes/pilot.h \
    src/classes/runguard.h \
    src/classes/settings.h \
    src/classes/stat.h \
    src/classes/strictrxvalidator.h \
    src/database/db.h \
    src/database/dbinfo.h \
    src/database/entry.h \
    src/gui/dialogues/firstrundialog.h \
    src/gui/dialogues/newflightdialog.h \
    src/gui/dialogues/newpilotdialog.h \
    src/gui/dialogues/newtaildialog.h \
    src/gui/widgets/aircraftwidget.h \
    src/gui/widgets/homewidget.h \
    src/gui/widgets/logbookwidget.h \
    src/gui/widgets/pilotswidget.h \
    src/gui/widgets/settingswidget.h \
    src/gui/widgets/totalswidget.h

FORMS += \
    mainwindow.ui \
    src/gui/dialogues/firstrundialog.ui \
    src/gui/dialogues/newflight.ui \
    src/gui/dialogues/newpilot.ui \
    src/gui/dialogues/newtail.ui \
    src/gui/widgets/aircraftwidget.ui \
    src/gui/widgets/homewidget.ui \
    src/gui/widgets/logbookwidget.ui \
    src/gui/widgets/pilotswidget.ui \
    src/gui/widgets/settingswidget.ui \
    src/gui/widgets/totalswidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



RESOURCES += \
    assets/icons.qrc \
    assets/themes/breeze.qrc

DISTFILES += \
    assets/themes/dark.qss \
    assets/themes/dark/branch_closed-on.svg \
    assets/themes/dark/branch_closed.svg \
    assets/themes/dark/branch_open-on.svg \
    assets/themes/dark/branch_open.svg \
    assets/themes/dark/checkbox_checked.svg \
    assets/themes/dark/checkbox_checked_disabled.svg \
    assets/themes/dark/checkbox_indeterminate.svg \
    assets/themes/dark/checkbox_indeterminate_disabled.svg \
    assets/themes/dark/checkbox_unchecked.svg \
    assets/themes/dark/checkbox_unchecked_disabled.svg \
    assets/themes/dark/close-hover.svg \
    assets/themes/dark/close-pressed.svg \
    assets/themes/dark/close.svg \
    assets/themes/dark/down_arrow-hover.svg \
    assets/themes/dark/down_arrow.svg \
    assets/themes/dark/down_arrow_disabled.svg \
    assets/themes/dark/hmovetoolbar.svg \
    assets/themes/dark/hsepartoolbar.svg \
    assets/themes/dark/left_arrow.svg \
    assets/themes/dark/left_arrow_disabled.svg \
    assets/themes/dark/radio_checked.svg \
    assets/themes/dark/radio_checked_disabled.svg \
    assets/themes/dark/radio_unchecked.svg \
    assets/themes/dark/radio_unchecked_disabled.svg \
    assets/themes/dark/right_arrow.svg \
    assets/themes/dark/right_arrow_disabled.svg \
    assets/themes/dark/sizegrip.svg \
    assets/themes/dark/spinup_disabled.svg \
    assets/themes/dark/stylesheet-branch-end-closed.svg \
    assets/themes/dark/stylesheet-branch-end-open.svg \
    assets/themes/dark/stylesheet-branch-end.svg \
    assets/themes/dark/stylesheet-branch-more.svg \
    assets/themes/dark/stylesheet-vline.svg \
    assets/themes/dark/transparent.svg \
    assets/themes/dark/undock-hover.svg \
    assets/themes/dark/undock.svg \
    assets/themes/dark/up_arrow-hover.svg \
    assets/themes/dark/up_arrow.svg \
    assets/themes/dark/up_arrow_disabled.svg \
    assets/themes/dark/vmovetoolbar.svg \
    assets/themes/dark/vsepartoolbars.svg \
    assets/themes/dark_original.qss \
    assets/themes/light.qss \
    assets/themes/light/branch_closed-on.svg \
    assets/themes/light/branch_closed.svg \
    assets/themes/light/branch_open-on.svg \
    assets/themes/light/branch_open.svg \
    assets/themes/light/checkbox_checked-hover.svg \
    assets/themes/light/checkbox_checked.svg \
    assets/themes/light/checkbox_checked_disabled.svg \
    assets/themes/light/checkbox_indeterminate-hover.svg \
    assets/themes/light/checkbox_indeterminate.svg \
    assets/themes/light/checkbox_indeterminate_disabled.svg \
    assets/themes/light/checkbox_unchecked-hover.svg \
    assets/themes/light/checkbox_unchecked_disabled.svg \
    assets/themes/light/close-hover.svg \
    assets/themes/light/close-pressed.svg \
    assets/themes/light/close.svg \
    assets/themes/light/down_arrow-hover.svg \
    assets/themes/light/down_arrow.svg \
    assets/themes/light/down_arrow_disabled.svg \
    assets/themes/light/hmovetoolbar.svg \
    assets/themes/light/hsepartoolbar.svg \
    assets/themes/light/left_arrow.svg \
    assets/themes/light/left_arrow_disabled.svg \
    assets/themes/light/radio_checked-hover.svg \
    assets/themes/light/radio_checked.svg \
    assets/themes/light/radio_checked_disabled.svg \
    assets/themes/light/radio_unchecked-hover.svg \
    assets/themes/light/radio_unchecked_disabled.svg \
    assets/themes/light/right_arrow.svg \
    assets/themes/light/right_arrow_disabled.svg \
    assets/themes/light/sizegrip.svg \
    assets/themes/light/spinup_disabled.svg \
    assets/themes/light/stylesheet-branch-end-closed.svg \
    assets/themes/light/stylesheet-branch-end-open.svg \
    assets/themes/light/stylesheet-branch-end.svg \
    assets/themes/light/stylesheet-branch-more.svg \
    assets/themes/light/stylesheet-vline.svg \
    assets/themes/light/transparent.svg \
    assets/themes/light/undock-hover.svg \
    assets/themes/light/undock.svg \
    assets/themes/light/up_arrow-hover.svg \
    assets/themes/light/up_arrow.svg \
    assets/themes/light/up_arrow_disabled.svg \
    assets/themes/light/vmovetoolbar.svg \
    assets/themes/light/vsepartoolbars.svg \
    assets/themes/light_original.qss \
    assets/themes/theme_license
