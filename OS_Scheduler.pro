#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T16:21:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OS_Scheduler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fcfs.cpp \
    priority.cpp \
    roundRobin.cpp \
    sjf.cpp

HEADERS  += mainwindow.h \
    Process.h \
    Scheduler.h \
    log.h

FORMS    += mainwindow.ui

CONFIG += c++11
