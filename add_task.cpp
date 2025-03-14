#include "add_task.h"
#include "ui_add_task.h"

Add_task::Add_task(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_task)
{
    ui->setupUi(this);
}

Add_task::~Add_task()
{
    delete ui;
}
