QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++2a

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AlbumListWidget.cpp \
    AlbumWidget.cpp \
    PictureDelegate.cpp \
    PictureWidget.cpp \
    ThumbnailProxyModel.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AlbumListWidget.h \
    AlbumWidget.h \
    MainWindow.h \
    PictureDelegate.h \
    PictureWidget.h \
    ThumbnailProxyModel.h

FORMS += \
    AlbumListWidget.ui \
    AlbumWidget.ui \
    MainWindow.ui \
    PictureWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../Core/ -lCore

INCLUDEPATH += $$PWD/../Core
DEPENDPATH += $$PWD/../Core

RESOURCES += \
    res/resource.qrc
