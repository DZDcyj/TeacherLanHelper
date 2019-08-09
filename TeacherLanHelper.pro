#-------------------------------------------------
#
# Project created by QtCreator 2019-06-21T11:11:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeacherLanHelper
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

SOURCES += \
        about.cpp \
        adminlogin.cpp \
        adminmenu.cpp \
        backingup.cpp \
        lanforum.cpp \
        laninfo.cpp \
        main.cpp \
        mainwindow.cpp \
        opensource.cpp \
        protectormain.cpp \
        saving.cpp \
        signup.cpp \
        updatelog.cpp

HEADERS += \
        about.h \
        adminlogin.h \
        adminmenu.h \
        backingup.h \
        lanforum.h \
        laninfo.h \
        mainwindow.h \
        opensource.h \
        protectormain.h \
        saving.h \
        signup.h \
        updatelog.h

FORMS += \
        about.ui \
        adminlogin.ui \
        adminmenu.ui \
        backingup.ui \
        lanforum.ui \
        laninfo.ui \
        mainwindow.ui \
        opensource.ui \
        protectormain.ui \
        saving.ui \
        signup.ui \
        updatelog.ui

INCLUDEPATH += "D:/Windows Kits/10/Include/10.0.17763.0/ucrt"

LIBS += -L"D:/Windows Kits/10/Lib/10.0.17763.0/ucrt/x64"
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
