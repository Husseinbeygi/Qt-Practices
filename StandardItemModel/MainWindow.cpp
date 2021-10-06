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

void MainWindow::init()
{

    QStringList list;
    list << "My Items";
    m_Model.setHorizontalHeaderLabels(list);

    QStandardItem *root = m_Model.invisibleRootItem();


    for (int i=0;i < 100 ;i++ ) {

        QStandardItem *parentitem = new QStandardItem(QString("Parent %0").arg(i));
        root->appendRow(parentitem);

        for (int i=0;i < 10 ;i++ ) {

            QStandardItem *childitem = new QStandardItem(QString("Child %0").arg(i));
            parentitem->appendRow(childitem);
            for (int i=0;i < 10 ;i++ ) {

                QStandardItem *item = new QStandardItem(QString("Item %0").arg(i));
                childitem->appendRow(item);


            }

        }
    }

    ui->treeView->setModel(&m_Model);

}

