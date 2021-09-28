#include "MainWindow.h"

#include <QApplication>
#include <SysInfo.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SysInfo::instance().init();
    w.show();
    return a.exec();
}
