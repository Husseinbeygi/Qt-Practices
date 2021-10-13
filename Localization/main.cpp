#include <QCoreApplication>
#include <iostream>
#include "Localization.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Localization::Manager manager;
    std::string color {manager.GetString(Localization::STRING_COLOR)};
    std::cout << "EN_US : " << color.c_str() << std::endl;
    manager.SetLanguages(Localization::Languages::EN_GB);
    color  = manager.GetString(Localization::STRING_COLOR);
    std::cout << "EN_GB : " << color.c_str() << std::endl;

    return a.exec();
}
