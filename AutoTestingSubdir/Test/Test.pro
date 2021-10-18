QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testcalculator.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Calculatorlib/release/ -lCalculatorlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Calculatorlib/debug/ -lCalculatorlib
else:unix: LIBS += -L$$OUT_PWD/../Calculatorlib/ -lCalculatorlib

INCLUDEPATH += $$PWD/../Calculatorlib
DEPENDPATH += $$PWD/../Calculatorlib
