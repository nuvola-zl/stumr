QT       += core gui
QT       +=sql
QT       +=charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dlg_addst.cpp \
    dlg_change.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    stusql.cpp \
    view.cpp

HEADERS += \
    dlg_addst.h \
    dlg_change.h \
    login.h \
    mainwindow.h \
    stusql.h \
    view.h

FORMS += \
    dlg_addst.ui \
    dlg_change.ui \
    login.ui \
    mainwindow.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
