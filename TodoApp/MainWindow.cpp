#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QPushButton>
#include <QDebug>
#include <QInputDialog>

#include <Task.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->BtnAddTask,&QPushButton::clicked,this,&MainWindow::AddTask);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddTask()
{
    bool ok;
    QString GetNameFromInputDialog = QInputDialog::getText(this,tr("Add Task"),tr("Task Name"),QLineEdit::Normal,tr("untitledTask"), &ok);
    if(ok && !GetNameFromInputDialog.isEmpty()) {
        qDebug() << "Adding a Task";
        Task* task = new Task(GetNameFromInputDialog);
        connect(task,&Task::Removed,this,&MainWindow::RemoveTask);
        connect(task,&Task::CheckboxChecked,this,&MainWindow::TaskStatusChenged);
        m_Task.append(task);
        ui->TaskLayout->addWidget(task);
        UpdateStatus();


    }

}

void MainWindow::RemoveTask(Task *task)
{
    m_Task.removeOne(task);
    ui->TaskLayout->removeWidget(task);
    delete task;

}

void MainWindow::TaskStatusChenged(Task* /*task*/)
{
    UpdateStatus();
}

void MainWindow::UpdateStatus()
{
    int completedCount = 0;
    for(auto t: m_Task){
        if (t->IsCompleted()) {
            completedCount++;
        }
    }
    int todocount = m_Task.size() - completedCount;
    ui->LblStatus->setText(QString("Status: %1 Todo / %2 Completed").arg(todocount).arg(completedCount));
}

