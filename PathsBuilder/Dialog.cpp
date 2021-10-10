#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    AddRoots();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_treeWidget_itemExpanded(QTreeWidgetItem *item)
{
    AddChildren(item);
}


void Dialog::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column)
    SetCheckState(item,item->checkState(0));
    GetChekedItems();

}


void Dialog::on_buttonBox_accepted()
{
    // accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::AddRoots()
{
    QFileInfoList drive = QDir::drives();
    ui->treeWidget->setHeaderHidden(true);


    foreach(QFileInfo file, drive) {
        ui->treeWidget->addTopLevelItem(CreateItem(file));
    }

    for (int i=0; i< ui->treeWidget->topLevelItemCount() ; i++) {

        QTreeWidgetItem *item = ui->treeWidget->topLevelItem(i);
        AddChildren(item);
    }



}

QTreeWidgetItem *Dialog::CreateItem(QFileInfo file)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    if (file.fileName().isEmpty()) {
        item->setText(0,file.filePath());
    }
    else {
        item->setText(0,file.fileName());
    }

    item->setCheckState(0,Qt::CheckState::Unchecked);
    item->setData(0,Qt::ItemDataRole::UserRole,file.filePath());

    AddExpander(item);

    return item;
}

void Dialog::AddExpander(QTreeWidgetItem *root)
{
    if(root->childCount() > 0) return;
    QFileInfo file(root->data(0,Qt::ItemDataRole::UserRole).toString());
    QDir dir(file.filePath());
    QFileInfoList list = dir.entryInfoList(QDir::Filter::Dirs | QDir::Filter::NoDotAndDotDot);
    if(list.count() == 0) return;

    root->addChild(new QTreeWidgetItem(QStringList() << "Scaning...."));


}

void Dialog::AddChildren(QTreeWidgetItem *root)
{

}

void Dialog::SetCheckState(QTreeWidgetItem *root, Qt::CheckState state)
{

}

void Dialog::GetChekedItems(QTreeWidgetItem *root)
{

}

void Dialog::GetChekedItems()
{

}

