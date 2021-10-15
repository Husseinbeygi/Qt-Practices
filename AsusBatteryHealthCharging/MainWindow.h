#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Battery.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QStringList>
#include <QSysInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:

  void on_btn_Box_accepted();

  void on_btn_Box_rejected();

private:
  void initial();
  QString GetOption(QObject *obj);
  Ui::MainWindow *ui;
  Battery *m_Battery;
  QString BatName = "";
  QMessageBox m_MessageBox;
  QString GenerateText(QString BatName, QString ChargePercent);
};
#endif // MAINWINDOW_H
