#ifndef BATTERY_H
#define BATTERY_H

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QObject>
#include <QStringList>

class Battery : public QObject {
  Q_OBJECT
public:
  explicit Battery(QObject *parent = nullptr);
  QStringList CheckForBatteryFile();
};

#endif // BATTERY_H
