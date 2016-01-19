#-------------------------------------------------
#
# Project created by QtCreator 2013-09-25T09:11:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CheVisualizer
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
        myglwidget.cpp \
        atom.cpp \
        chemical.cpp

        HEADERS  += atom.h \
    chemical.h \
    window.h \
    myglwidget.h

FORMS    += window.ui
