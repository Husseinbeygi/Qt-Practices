QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++2a

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CpuWidget.cpp \
    MemoryWidget.cpp \
    SysInfo.cpp \
    SysInfoLinuxImpl.cpp \
    SysInfoMacImpl.cpp \
    SysInfoWidget.cpp \
    SysInfoWindowsImpl.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    CpuWidget.h \
    MainWindow.h \
    MemoryWidget.h \
    SysInfo.h \
    SysInfoLinuxImpl.h \
    SysInfoMacImpl.h \
    SysInfoWidget.h \
    SysInfoWindowsImpl.h


FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
