#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>

class Widget : public QObject {
  Q_OBJECT
public:
  explicit Widget(QObject *parent = nullptr);
  void SetAge(int val);

  int age;
signals:

private:
};

#endif // WIDGET_H
