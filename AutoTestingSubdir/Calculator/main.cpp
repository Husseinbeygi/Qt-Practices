#include <Calculatorlib.h>
#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  int A, B;
  cout << "Number A : ";
  cin >> A;
  cout << "Number B : ";
  cin >> B;
  Calculatorlib calc(A, B);
  int res = calc.Mult();
  qDebug() << "Result : " << res;

  return a.exec();
}
