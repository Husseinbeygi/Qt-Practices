#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_CpuWidget(this)
{
    ui->setupUi(this);
    ui->centralwidget->setLayout(new QHBoxLayout());
    ui->centralwidget->layout()->addWidget(&m_CpuWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

