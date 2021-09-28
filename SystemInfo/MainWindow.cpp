#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_CpuWidget(this),m_MemoryWidget(this)
{
    ui->setupUi(this);
    ui->centralwidget->setLayout(new QHBoxLayout());
    ui->centralwidget->layout()->addWidget(&m_CpuWidget);
    ui->centralwidget->layout()->addWidget(&m_MemoryWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

