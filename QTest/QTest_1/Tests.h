#ifndef TESTS_H
#define TESTS_H

#include "Widget.h"
#include <QObject>
#include <QTest>

class Tests : public QObject {
  Q_OBJECT
public:
  explicit Tests(QObject *parent = nullptr);
  void Run();
signals:
private:
  Widget widget;
private slots:
  void TestAge();
  void TestFail();
  void TestUseMacros();
};

#endif // TESTS_H
