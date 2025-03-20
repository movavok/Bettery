#include <QDebug>
#include <QTextBrowser>
#include "add_task.h"
#include "mainwindow.h"
#include "ui_add_task.h"

bool pressed = false;

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
void Add_task::on_b_ready_clicked()
{
    QString added_task = ui->le_task->text();
    qDebug() << added_task;
    emit signal(added_task);

    hide();
}

void Add_task::on_b_pickMon_clicked()
{
    pressed = !pressed;
    qDebug() << "button pressed:" << pressed;
}

