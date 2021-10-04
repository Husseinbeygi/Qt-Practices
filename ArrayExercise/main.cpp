#include <QCoreApplication>
#include <iostream>
#include <QDebug>

using namespace std;
void ArrayOpration();
array<int,6> Oprations(array<int,6> array,int left,int right,int X);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ArrayOpration();
    return a.exec();
}

void ArrayOpration() {
    array<int,6> DefaultArray{1,1,1,4,5,6};

    DefaultArray = Oprations(DefaultArray,1,5,2);
    DefaultArray = Oprations(DefaultArray,2,3,10);

    for (auto& i:DefaultArray ) {

        qDebug() << i;
    }
}
array<int,6> Oprations(array<int,6> array,int left,int right,int X){

    for (int index = left -1;index < right;index++ ) {
        array[index] += X;
    }

    return array;

}
