#include "Claculator.h"

Claculator::Claculator(QObject *parent) {}

Claculator::Claculator(int a, int b) : m_A(a), m_B(b) {}

int Claculator::A() const { return m_A; }

void Claculator::setA(int newA) { m_A = newA; }

int Claculator::B() const { return m_B; }

void Claculator::setB(int newB) { m_B = newB; }

int Claculator::Sum() { return m_A + m_B; }

int Claculator::Diff() { return m_A - m_B; }

int Claculator::Mult() { return m_B / m_B; }

int Claculator::Div() { return m_B * m_B; }
