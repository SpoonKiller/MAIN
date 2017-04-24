#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T12:51:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MAIN
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    neuron.cpp \
    paintscene.cpp

HEADERS  += widget.h \
    neuron.h \
    const.h \
    paintscene.h

FORMS    += widget.ui
