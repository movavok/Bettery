#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_task.h"
#include "time_set_win.h"

bool info_closed = true;

void MainWindow::slot(QString task)
{
    QString taskHtml = QString("<a href=\"#task%1\"><span style=\" font-size:12pt; font-weight:700;"
                               " text-decoration: underline; color:#4c3535;\">• %2</span></a>").arg(taskId).arg(task);

    crossed_tasks[arg1] = false;

    ui->txt_tasks->append(taskHtml);
    old_txt = ui->txt_tasks->toHtml();
    taskId++;
}

void MainWindow::get_time(int firsttime, int secondtime){
    this->firsttime = firsttime;
    this->secondtime = secondtime;

    ui->day_progress->setMinimum(firsttime * 60);
    ui->day_progress->setMaximum(secondtime * 60);

    qDebug() << "Updated firsttime:" << firsttime << "secondtime:" << secondtime;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->b_time_set->hide();
    ui->txt_tasks->setOpenLinks(false);
    ui->b_info->installEventFilter(this);

    ui->day_progress->setMinimum(540);    // 09:00
    ui->day_progress->setMaximum(1380);   // 23:00

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::day_progress);
    timer->start(60000);

    day_progress();
    connect(ui->txt_tasks, &QTextBrowser::anchorClicked, this, &MainWindow::on_txt_tasks_anchorClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_button_clicked() // Открытие окна для добавления задачи
{
    Add_task add_task;
    add_task.setModal(true);
    connect(&add_task, &Add_task::signal, this, &MainWindow::slot);
    add_task.exec();
}

void MainWindow::on_b_time_set_clicked() // Открытие окна с настройкой времени для ПрогрессБара
{
    time_set_win ts_win;
    connect(&ts_win, &time_set_win::give_time, this, &MainWindow::get_time);
    ts_win.setModal(true);
    ts_win.exec();
}

void MainWindow::day_progress() // ПрогрессБар длины дня
{
    QTime now = QTime::currentTime();

    int min_conver = now.hour()*60 + now.minute();
    ui->day_progress->setValue(min_conver);
    qDebug() << min_conver;
}

void MainWindow::on_txt_tasks_anchorClicked(const QUrl &arg1) // страшные зачеркивания и расчеркивания
{
    if (debounceTimer && debounceTimer->isActive())
        return;
    if (!debounceTimer) {
        debounceTimer = new QTimer(this);
        debounceTimer->setSingleShot(true);
    }
    debounceTimer->start(1);

    ui->txt_tasks->setSource(QUrl());
    qDebug() << "Нажата строка:" << arg1;

    QString taskUrl = arg1.toString();
    QString cur_txt = ui->txt_tasks->toHtml();

    if (!crossed_tasks[arg1]) {
        crossed_tasks[arg1] = true;
        qDebug() << "Зачеркнуто";
        QString startff = QString("<a href=\"%1\"").arg(taskUrl); // зачеркивание
        int startff_index = cur_txt.indexOf(startff);
        if (startff_index != -1) {
            int ffend_index = cur_txt.indexOf("</a>", startff_index);
            if (ffend_index != -1) {
                QString old_task = cur_txt.mid(startff_index, ffend_index - startff_index + 4);
                cur_txt.remove(startff_index, ffend_index - startff_index + 4); // 4 = </a> :)
                cur_txt.insert(startff_index, QString("<span style='text-decoration: underline line-through;"
                                                      " color:#b89f9f;'>%1</span>").arg(old_task));
                cur_txt.replace(
                    QString("<a href=\"%1\"><span style=\" font-size:12pt; font-weight:700;"
                            " text-decoration: underline; color:#4c3535;\">").arg(taskUrl),
                    QString("<a href=\"%1\"><span style=\" font-size:12pt; font-weight:700;"
                            " text-decoration: underline; color:#b89f9f;\">").arg(taskUrl)
                    );
                ui->txt_tasks->setHtml(cur_txt);
            }
        }
    } else {
        crossed_tasks[arg1] = false;
        qDebug() << "Задача снова активна";
        QString startff = QString("<a href=\"%1\"").arg(taskUrl); // зачеркивание
        int startff_index = cur_txt.indexOf(startff);
        if (startff_index != -1) {
            int ffend_index = cur_txt.indexOf("</a>", startff_index);
            if (ffend_index != -1) {
                QString old_task = cur_txt.mid(startff_index, ffend_index - startff_index + 4);
                old_task = old_task.replace("line-through;", "");
                cur_txt.remove(startff_index, ffend_index - startff_index + 4);
                cur_txt.insert(startff_index, old_task);
                cur_txt.replace(
                    QString("<a href=\"%1\"><span style=\" font-size:12pt; font-weight:700;"
                            " text-decoration: underline  color:#b89f9f;\">").arg(taskUrl),
                    QString("<a href=\"%1\"><span style=\" font-size:12pt; font-weight:700;"
                            " text-decoration: underline; color:#4c3535;\">").arg(taskUrl)
                    );
                ui->txt_tasks->setHtml(cur_txt);
            }
        }
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) // Наведение на кнопку с информацией
{
    if (obj == ui->b_info && info_closed == false) {
        if (event->type() == QEvent::Enter){
            QString tt_info = QString("<b><span style=\" "
                                      "color:#4c3535;\">"
                                      "Слева ты можешь наблюдать\nполосу, что отображает\nдлительность дня\n"
                                      "с <a href=\"#first_hour\">%1</a> до <a href=\"#second_hour\">%2</a> часов."
                                      "</span></b>").arg(firsttime).arg(secondtime);
            QToolTip::showText(QCursor::pos(), tt_info); // отображение информации об прогрессбаре
        }
        else if (event->type() == QEvent::Leave){
        }

    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::on_b_info_clicked() // Блокировка кнопки с информацией
{
    info_closed = !info_closed;
    if (info_closed == true){
        ui->b_info->setText("><");
        ui->b_time_set->hide();
    }
    else{
        ui->b_info->setText("?");
        ui->b_time_set->show();
    }
}

