QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG -= debug_and_release

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../src/loading_widget.pri)

TARGET = loading_test

CONFIG(debug,debug|release) {
    MOC_DIR     = ../temp/debug/
    RCC_DIR     = ../temp/debug/
    UI_DIR      = ../temp/debug/
    OBJECTS_DIR = ../temp/debug/
    DESTDIR     = ../bin/debug/
}

CONFIG(release,debug|release) {
    MOC_DIR     = ../temp/release/
    RCC_DIR     = ../temp/release/
    UI_DIR      = ../temp/release/
    OBJECTS_DIR = ../temp/release/
    DESTDIR     = ../bin/release/
}

SOURCES += \
    main.cpp \
    loadingtestwidget.cpp

HEADERS += \
    loadingtestwidget.h

FORMS += \
    loadingtestwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
