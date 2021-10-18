#include <QtTest>

// add necessary includes here
#include <Calculatorlib.h>

class TestCalculator : public QObject {
  Q_OBJECT

public:
  TestCalculator();
  ~TestCalculator();

private slots:
  void test_sum();
  void test_diff();
  void test_mult();
  void test_div();

private:
  Calculatorlib mCalc;
};

TestCalculator::TestCalculator() {
  Calculatorlib calc;

  QVERIFY(calc.A() == 0);
  QVERIFY(calc.B() == 0);

  const int A = 10;
  const int B = 2;
  Calculatorlib calc1(A, B);

  QVERIFY2(calc1.A() == A, "A operand doesn't match");
  QVERIFY2(calc1.B() == B, "B operand doesn't match");
}

TestCalculator::~TestCalculator() {}

void TestCalculator::test_sum() {
  const int A = 10;
  const int B = 2;
  mCalc.setA(A);
  mCalc.setB(B);

  QCOMPARE(mCalc.Sum(), A + B);
}

void TestCalculator::test_diff() {
  const int A = 10;
  const int B = 2;
  mCalc.setA(A);
  mCalc.setB(B);

  QCOMPARE(mCalc.Diff(), A - B);
}

void TestCalculator::test_mult() {
  const int A = 10;
  const int B = 2;
  mCalc.setA(A);
  mCalc.setB(B);

  QCOMPARE(mCalc.Mult(), A * B);
}

void TestCalculator::test_div() {
  const int A = 10;
  const int B = 2;
  mCalc.setA(A);
  mCalc.setB(B);

  QCOMPARE(mCalc.Div(), A / B);
}

QTEST_APPLESS_MAIN(TestCalculator)

#include "tst_testcalculator.moc"
