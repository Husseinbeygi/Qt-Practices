#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QDebug>
#include <QStack>

using namespace std;

/* Functions are Decalred here*/
bool Verfiy(array<QString,10> InputParenthesis);
void ParenthesisCheck(QStack<int>* ParenthesisStack,QString p);
void ClosedParenthesisCheck(QStack<int>* ParenthesisStack,int numberp);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    array<QString,10> Parenthesis {"(","{","[","]","}",")"};
    qDebug() << Verfiy(Parenthesis);
    return a.exec();
}

bool Verfiy(array<QString,10> InputParenthesis) {
    QStack<int> ParenthesisStack ;

    for (auto& p:InputParenthesis ) {
        ParenthesisCheck(&ParenthesisStack, p);
    }
    if (ParenthesisStack.isEmpty()) {
        return true;
    }
        return false;

}

void ParenthesisCheck(QStack<int>* ParenthesisStack,QString p)
{
    if (p == "(") {
        ParenthesisStack->push(1);
    }
    else if (p == "[") {
        ParenthesisStack->push(2);
    }
    else if (p == "{") {
        ParenthesisStack->push(3);
    }
    else if (p == ")") {
        ClosedParenthesisCheck(ParenthesisStack,1);

    }
    else if (p == "]") {
        ClosedParenthesisCheck(ParenthesisStack,2);

    }
    else if (p == "}") {
        ClosedParenthesisCheck(ParenthesisStack,3);
    }
}

void ClosedParenthesisCheck(QStack<int>* ParenthesisStack,int numberp) {
    if (!ParenthesisStack->isEmpty() || ParenthesisStack->top() == numberp) {
        ParenthesisStack->pop();
    }
}
