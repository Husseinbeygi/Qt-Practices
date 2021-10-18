#include "Widget.h"

Widget::Widget(QObject *parent) : QObject(parent) { age = 0; }

void Widget::SetAge(int val) { age = val; }
