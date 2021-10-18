#include "Tests.h"

Tests::Tests(QObject *parent) : QObject(parent) {}

void Tests::Run() { QTest::qExec(this); }

void Tests::TestAge() {
  if (widget.age > 0) {

    qInfo() << "The age is set to the variable";
  } else {
    QSKIP("The age is NOT set to the variable");
  }
}

void Tests::TestFail() { QFAIL("JUST FOR FAILING THE TEST"); }

void Tests::TestUseMacros() {
  int val = 20;
  QCOMPARE(widget.age, val);
}
