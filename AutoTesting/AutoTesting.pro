QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testcalculator.cpp \
    Claculator.cpp

HEADERS += \
    Claculator.h
