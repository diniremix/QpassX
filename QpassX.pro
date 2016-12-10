#-------------------------------------------------
#
# Project created by QtCreator 2016-12-04T21:49:19
#
#-------------------------------------------------

QT       += core gui

QT+=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QpassX
TEMPLATE = app


SOURCES += main.cpp\
        qpassx.cpp \
    qdatabase.cpp

HEADERS  += qpassx.h \
    qdatabase.h

FORMS    += qpassx.ui

RESOURCES += \
    resources.qrc
