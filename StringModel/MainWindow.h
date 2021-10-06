#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QInputDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void add();
    void Remove();


private:
    Ui::MainWindow *ui;
    void init();

    QStringList m_List;
    QStringListModel m_Model;
};
#endif // MAINWINDOW_H
