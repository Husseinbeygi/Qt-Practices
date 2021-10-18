
#include "Tests.h"
#include "Widget.h"
#include <QCoreApplication>
#include <QTest>
int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  Widget widget;
  widget.SetAge(20);
  //  QTest::qExec(&widget);
  Tests test;
  test.Run();
  return a.exec();
}
