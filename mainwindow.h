#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QMap>
#include <QTextBrowser>
#include <QDebug>
#include <QToolTip>

#include "add_task.h"
#include "time_set_win.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void slot(QString task);
    void get_time(int firsttime, int secondtime);


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool eventFilter(QObject *obj, QEvent *event) override; // Наведение на кнопку с информацией

private slots:
    void on_add_button_clicked();
    void day_progress();
    void on_txt_tasks_anchorClicked(const QUrl &arg1);

    void on_b_info_clicked();

    void on_b_time_set_clicked();

private:
    Ui::MainWindow *ui;

    int taskId = 0;
    QUrl arg1;
    QString taskHtml;
    QMap<QUrl, bool> crossed_tasks;
    QString old_txt;

    int firsttime;
    int secondtime;

    Add_task *add_task;

    QTimer *timer; // таймер

    QTimer *debounceTimer = nullptr; // контра повторного вызова ссылки  
};

#endif // MAINWINDOW_H
