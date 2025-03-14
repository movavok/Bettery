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

private:
    Ui::Add_task *ui;
};

#endif // ADD_TASK_H
