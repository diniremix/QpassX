#-------------------------------------------------
# Author:
#	Jorge Brunal A.K.A. Diniremix: https://github.com/diniremix
#
# Copyright:
#    Copyright (C) 2016-2019 Jorge Brunal A.K.A. Diniremix
#
# License:	LGPL-2.1
# The full text of the licenses can be found in the LGPL' files.
#
# Project created by QtCreator 2019-07-16T23:12:34
#
#-------------------------------------------------

QT  += core gui
QT  += sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QpassX
TEMPLATE = app


SOURCES += main.cpp\
        qpassx.cpp \
    formnew.cpp \
    auth.cpp \
    lib/firebase.cpp \
    lib/qdatabase.cpp

HEADERS += qpassx.h \
    formnew.h \
    auth.h \
    lib/firebase.h \
    lib/qdatabase.h

FORMS   += qpassx.ui \
    formnew.ui

INCLUDEPATH += \
    lib \
    resources

RESOURCES += resources/resources.qrc

RC_ICONS = resources/carbon-icon.ico

# DESTDIR = $$PWD/../build
