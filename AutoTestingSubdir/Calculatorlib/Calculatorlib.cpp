#include "Calculatorlib.h"

Calculatorlib::Calculatorlib() {}

Calculatorlib::Calculatorlib(int a, int b) : m_A(a), m_B(b) {}

int Calculatorlib::Sum() { return m_A + m_B; }

int Calculatorlib::Diff() { return m_A - m_B; }

int Calculatorlib::Mult() { return m_A * m_B; }

int Calculatorlib::Div() { return m_A / m_B; }

int Calculatorlib::A() const { return m_A; }

void Calculatorlib::setA(int newA) { m_A = newA; }

int Calculatorlib::B() const { return m_B; }

void Calculatorlib::setB(int newB) { m_B = newB; }
