#ifndef CLACULATOR_H
#define CLACULATOR_H

#include <QObject>

class Claculator : public QObject {
  Q_OBJECT
public:
  explicit Claculator(QObject *parent = nullptr);
  Claculator(int a, int b);
  int A() const;
  void setA(int newA);

  int B() const;
  void setB(int newB);

  int Sum();
  int Diff();
  int Mult();
  int Div();
signals:

private:
  int m_A;
  int m_B;
};

#endif // CLACULATOR_H
