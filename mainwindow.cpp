#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->day_progress->setMinimum(0);    // 00:00
    ui->day_progress->setMaximum(1439); // 23:59

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::day_progress);
    timer->start(60000);

    day_progress();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_button_clicked()
{
    //QMessageBox::about(this, "Calendar", "week");
    Add_task window;
    window.setModal(true);
    window.exec();
}


void MainWindow::day_progress()
{
    QTime now = QTime::currentTime();

    int min_conver = now.hour()*60 + now.minute();
    ui->day_progress->setValue(min_conver);
    qDebug() << min_conver;
}

