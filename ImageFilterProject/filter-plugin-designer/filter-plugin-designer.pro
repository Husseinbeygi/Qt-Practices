QT += widget uiplugin
CONFIG += plugin
CONFIG += c++20
TEMPLATE = lib
DEFINES += FILTERPLUGINDESIGNER_LIBRARY

TARGET = $$qtLibraryTarget($$TARGET)
INSTALLS =+TARGET
