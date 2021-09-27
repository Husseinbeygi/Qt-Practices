#include "Task.h"
#include "ui_Task.h"

#include <QInputDialog>
#include <QDebug>

Task::Task(const QString& name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    SetName(name);
    connect(ui->BtnEditTask,&QPushButton::clicked,this,&Task::Rename);

    /*
    here is to connect the clicked signal to an anonymous inline function, a
    lambda . Qt allows signal relaying by connecting a signal to another signal if their signatures
    match. It's not the case here; the clicked signal has no parameter and the removed signal
    needs a Task* . A lambda avoids the declaration of a verbose slot in Task . Qt 5 accepts
    a lambda instead of a slot in a connect , and both syntaxes can be used.
    */
    connect(ui->BtnRemoveTask,&QPushButton::clicked,[this , name]{qDebug() << "Trying to Remove" << name;
        emit Removed(this);});

    connect(ui->ChkbxTask,&QCheckBox::toggled,this,&Task::StatusChanged);
}

Task::~Task()
{
    delete ui;
}

void Task::SetName(const QString &name)
{
    ui->ChkbxTask->setText(name);
}

QString Task::Name() const
{
    return ui->ChkbxTask->text();
}

bool Task::IsCompleted() const
{
    return ui->ChkbxTask->isChecked();
}

void Task::Rename()
{
    bool ok;
    QString GetNameFromInputDialog = QInputDialog::getText(this,tr("Edit Text"),tr("Task Name"),QLineEdit::Normal,this->Name(), &ok);

    if(ok && !GetNameFromInputDialog.isEmpty()) {
        SetName(GetNameFromInputDialog);
    }

}

void Task::StatusChanged(bool checked)
{
    QFont font(ui->ChkbxTask->font());
    font.setStrikeOut(checked);
    ui->ChkbxTask->setFont(font);
    emit CheckboxChecked(this);

}


