#include "Battery.h"

Battery::Battery(QObject *parent) : QObject(parent) {}

QStringList Battery::CheckForBatteryFile() {
  QDir directory("/sys/class/power_supply/");

  QStringList dirs = directory.entryList(QStringList() << "BAT*");

  return dirs;
}
