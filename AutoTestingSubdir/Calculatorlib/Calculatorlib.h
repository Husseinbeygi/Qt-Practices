#ifndef CALCULATORLIB_H
#define CALCULATORLIB_H

#include "Calculatorlib_global.h"

class CALCULATORLIB_EXPORT Calculatorlib {
public:
  Calculatorlib();
  Calculatorlib(int a, int b);

  int Sum();
  int Diff();
  int Mult();
  int Div();

  int A() const;
  void setA(int newA);

  int B() const;
  void setB(int newB);

private:
  int m_A;
  int m_B;
};

#endif // CALCULATORLIB_H
