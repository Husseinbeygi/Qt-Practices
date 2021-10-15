#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowFlag(Qt::Dialog);
  initial();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::initial() {
  QStringList BatDir = m_Battery->CheckForBatteryFile();
  if (BatDir.count() < 0) {
    m_MessageBox.setText("Your device don't support the battery health");
    m_MessageBox.exec();
  } else {
    ui->cmb_BatteryName->insertItems(0, BatDir);
  }
}

QString MainWindow::GetOption(QObject *obj) {
  QString value = "None";
  QList<QRadioButton *> list =
      obj->findChildren<QRadioButton *>(QString(), Qt::FindDirectChildrenOnly);

  foreach (QRadioButton *rdo, list) {
    if (rdo->isChecked()) {
      value = rdo->text();
      break;
    }
  }

  return value;
}

QString MainWindow::GenerateText(QString BatName, QString ChargePercent) {

  return QString("[Unit]\
                          Description=Set the battery charge threshold\
                          After=multi-user.target\
                          StartLimitBurst=0\
                          \
                          [Service]\
                          Type=oneshot\
                          Restart=on-failure\
                          ExecStart=/bin/bash -c 'echo %1 > /sys/class/power_supply/%0/charge_control_end_threshold'\
                          \
                          [Install]\
                          WantedBy=multi-user.target")
      .arg(BatName, ChargePercent);
}

bool MainWindow::createFile(QString BatName, QString ChargePercent) {
  QFile file("/etc/systemd/system/battery-charge-threshold1.service");
  if (!file.open(QIODevice::WriteOnly)) {
    qWarning() << file.errorString();
    return false;
  }

  QTextStream stream(&file);
  QString banner = GenerateText(BatName, ChargePercent);
  qInfo() << "Writing " << banner;
  stream << banner;

  file.close();

  return true;

  //  QProcess::execute(
  //      QString("echo '<password>' | sudo -S mkdir "
  //              "/etc/systemd/system/battery-charge-threshold111.service"));
  //  return QProcess::execute(
  //      QString("echo '<password>' | sudo -S echo "
  //              "/etc/systemd/system/battery-charge-threshold111.service <
  //              %0")
  //          .arg(GenerateText(BatName, ChargePercent)));
}

void MainWindow::on_btn_Box_accepted() {
  QString option = GetOption(ui->groupBox);
  if (option == "Full Capacity Mode") {

    qDebug() << createFile(ui->cmb_BatteryName->currentText(), "100");

  } else if ("Maximum Life Span Mode") {
    qDebug() << GenerateText(ui->cmb_BatteryName->currentText(), "60");
  }
}

void MainWindow::on_btn_Box_rejected() {}
