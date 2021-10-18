#include <QtTest>

// add necessary includes here
#include "Claculator.h"

class TestCalculator : public QObject {
  Q_OBJECT

public:
  TestCalculator();
  ~TestCalculator();

private slots:
  void test_sum();

private:
  const int A0 = 0;
  const int B0 = 0;

  Claculator mCalc;
};

TestCalculator::TestCalculator() {
  Claculator calc;

  QVERIFY(calc.A() == 0);
  QVERIFY(calc.B() == 0);

  const int A = 10;
  const int B = 2;
  Claculator calc1(A, B);

  QVERIFY2(calc1.A() == A, "A operand doesn't match");
  QVERIFY2(calc1.B() == B, "B operand doesn't match");
}

TestCalculator::~TestCalculator() {}

void TestCalculator::test_sum() {

  // sum default
  // QCOMPARE(mCalc.Sum(), A0 + B0);

  // sum after setting a and b
  const int A = 10;
  const int B = 2;
  mCalc.setA(A);
  mCalc.setB(B);

  QCOMPARE(mCalc.Sum(), A + B);
}

QTEST_APPLESS_MAIN(TestCalculator)

#include "tst_testcalculator.moc"
