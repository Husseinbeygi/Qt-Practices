#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileSystemModel>
#include <QString>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();
private slots:
    void on_treeView_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

   QFileSystemModel m_Dir;
   QFileSystemModel m_File;
};
#endif // MAINWINDOW_H
