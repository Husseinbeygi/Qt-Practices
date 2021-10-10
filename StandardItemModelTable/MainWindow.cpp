#include "MainWindow.h"
#include "ui_MainWindow.h"

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

void MainWindow::itemChanged(QStandardItem *item)
{
    qDebug() << "Index:" << item->index().row() << "," << item->index().column() << "=" << item->text();
}

void MainWindow::init()
{
    m_Model.insertRows(0,4);
    m_Model.insertColumns(0,4);

    for (int i=0;i< 5 ;i++ ) {
        for (int j=0;j< 5 ;j++ ) {
            QStandardItem *item = new QStandardItem(QString("Row %0 Col %1").arg(i).arg(j));
            m_Model.setItem(i,j,item);

        }
    }

    ui->tableView->setModel(&m_Model);

    connect(&m_Model,&QStandardItemModel::itemChanged,this,&MainWindow::itemChanged);
}

