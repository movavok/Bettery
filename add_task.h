#ifndef ADD_TASK_H
#define ADD_TASK_H

#include <QDialog>

namespace Ui {
class Add_task;
}

class Add_task : public QDialog
{
    Q_OBJECT

public:
    explicit Add_task(QWidget *parent = nullptr);
    ~Add_task();

private slots:
    void on_b_ready_clicked();

    void on_b_pickMon_clicked();

private:
    Ui::Add_task *ui;

signals:
    void signal(QString task);
};

#endif // ADD_TASK_H
