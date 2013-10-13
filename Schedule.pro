#-------------------------------------------------
#
# Project created by QtCreator 2013-09-29T22:55:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Schedule
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
	mainwidget.cpp \
    timebarwidget.cpp \
    finishedwidget.cpp \
    failedwidget.cpp \
    scheduleview.cpp \
    timeshaftitem.cpp \
    taskitem.cpp

HEADERS  += mainwindow.h \
	mainwidget.h \
    timebarwidget.h \
    finishedwidget.h \
    failedwidget.h \
    sdk.h \
    scheduleview.h \
    timeshaftitem.h \
    taskitem.h
