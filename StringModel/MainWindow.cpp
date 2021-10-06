#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    m_List.append("Cat");
    m_List.append("Dog");
    m_List.append("Bird");
    m_List.append("Fish");

    m_Model.setStringList(m_List);
    ui->listView->setModel(&m_Model);

    QPushButton *btnAdd = new QPushButton("Add",this);
    QPushButton *btnRemove = new QPushButton("Remove",this);

    ui->buttonBox->addButton(btnAdd,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnRemove,QDialogButtonBox::ButtonRole::ActionRole);

    connect(btnAdd,&QPushButton::clicked,this,&MainWindow::add);
    connect(btnRemove,&QPushButton::clicked,this,&MainWindow::Remove);


}


void MainWindow::on_buttonBox_accepted()
{

}

void MainWindow::on_buttonBox_rejected()
{

}

void MainWindow::add()
{
    QString value = QInputDialog::getText(this,"Add","Write new animal");
    if(value.isEmpty()) return;

    if (m_Model.insertRow(m_Model.rowCount())) {
        QModelIndex index = m_Model.index(m_Model.rowCount() - 1);
        m_Model.setData(index,value);
    }

}

void MainWindow::Remove()
{
    QModelIndex index = ui->listView->currentIndex();
    m_Model.removeRow(index.row());
}

