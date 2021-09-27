#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <Task.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void AddTask();
    void RemoveTask(Task* task);
    void TaskStatusChenged(Task* task);
private:
    Ui::MainWindow *ui;
    QVector<Task *> m_Task;
    void UpdateStatus();
};
#endif // MAINWINDOW_H
