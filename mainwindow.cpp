#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_task.h"

bool info_closed = false;

void MainWindow::slot(QString task)
{
    QString taskHtml = QString("<a href=\"#task%1\"><span style=\" font-size:12pt; font-weight:700;"
                               " text-decoration: underline; color:#4c3535;\">• %2</span></a>").arg(taskId).arg(task);

    crossed_tasks[arg1] = false;

    ui->txt_tasks->append(taskHtml);
    old_txt = ui->txt_tasks->toHtml();
    taskId++;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txt_tasks->setOpenLinks(false);
    ui->b_info->installEventFilter(this);

    ui->day_progress->setMinimum(540);    // 09:00
    ui->day_progress->setMaximum(1380); // 23:00

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

void MainWindow::on_add_button_clicked()
{
    Add_task add_task;
    add_task.setModal(true);
    connect(&add_task, &Add_task::signal, this, &MainWindow::slot);
    add_task.exec();
}


void MainWindow::day_progress()
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
        if (event->type() == QEvent::Enter)
            QToolTip::showText(QCursor::pos(), "<b><span style=\" "
                                               "color:#4c3535;\">"
                                               "Слева ты можешь наблюдать\nполосу, что отображает\nдлительность дня\n"
                                               "<a href=\"#time\">с 9 до 23 часов.</a>"
                                               "</span></b>"); // отображение информации об прогрессбаре
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::on_b_info_clicked()
{
    info_closed = !info_closed;
    if (info_closed == true){
        ui->b_info->setText("><");
    }
    else{
        ui->b_info->setText("?");
    }
}

