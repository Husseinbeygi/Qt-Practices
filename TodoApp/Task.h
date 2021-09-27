#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>
#include <QCheckBox>
#include <QFont>
namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString& name,QWidget *parent = nullptr);
    ~Task();

    void SetName(const QString &name);
    QString Name() const;
    bool IsCompleted() const;
public slots:
    void Rename();
    void StatusChanged(bool checked);
signals:
    void Removed(Task* task);
    void CheckboxChecked(Task* task);
private:
    Ui::Task *ui;
};

#endif // TASK_H
