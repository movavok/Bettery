#include "mainwindow.h"
#include "add_task.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //QMessageBox::about(this, "Calendar", "week");
    Add_task window;
    window.setModal(true);
    window.exec();
}

