#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QMap>
#include <QTextBrowser>
#include <QDebug>

#include "add_task.h"

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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_button_clicked();
    void day_progress();
    void on_txt_tasks_anchorClicked(const QUrl &arg1);

private:
    Ui::MainWindow *ui;

    int taskId = 0;
    QUrl arg1;
    QString taskHtml;
    QMap<QUrl, bool> crossed_tasks;
    QString old_txt;

    Add_task *add_task;

    QTimer *timer; // таймер

    QTimer *debounceTimer = nullptr; // контра повторного вызова ссылки

protected:
    //void enterEvent(QEnterEvent *event) override;
};

#endif // MAINWINDOW_H
