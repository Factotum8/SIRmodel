#-------------------------------------------------
#
# Project created by QtCreator 2016-12-02T11:45:53
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIRmodel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    human.cpp \
    qcustomplot.cpp \
    formgraphhuman.cpp

HEADERS  += mainwindow.h \
    human.h \
    qcustomplot.h \
    formgraphhuman.h

FORMS    += mainwindow.ui \
    formgraphhuman.ui
