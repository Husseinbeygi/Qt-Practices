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
    m_Dir.setRootPath(QDir::currentPath());
    m_Dir.setFilter(QDir::Filter::Dirs | QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot);

    ui->treeView->setModel(&m_Dir);

    for (int i = 1; i<m_Dir.columnCount() ; i++ ) {
        ui->treeView->hideColumn(i);
    }

    m_File.setRootPath(m_Dir.rootPath());
    m_File.setFilter(QDir::Filter::Files);

    ui->listView->setModel(&m_File);

}


void MainWindow::on_treeView_activated(const QModelIndex &index)
{
    QString path = m_Dir.filePath(index);
    qDebug() << path;
    m_File.setFilter(QDir::Filter::Files);
    ui->listView->setRootIndex(m_File.setRootPath(path));


}

