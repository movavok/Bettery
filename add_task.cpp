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
    if(pressed){
        QString added_task = ui->le_task->text();
        qDebug() << added_task;
        emit signal(added_task);

        hide();
    }
    else{
        QString added_task = ui->le_task->text();
        ui->le_task->setText(added_task + " <Выбери день(и) недели>");
    }
}

void Add_task::on_b_pickMon_clicked()
{
    pressed = !pressed;

    QString cur_txt = ui->le_task->text();
    if (cur_txt.contains(" <Выбери день(и) недели>")) {
        cur_txt.replace(" <Выбери день(и) недели>", "");
        ui->le_task->setText(cur_txt);
    }
    qDebug() << "button pressed:" << pressed;
}

