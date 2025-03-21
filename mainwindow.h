#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
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

private:
    Ui::MainWindow *ui;

    Add_task *add_task;

    QTextBrowser *textBrowser; // Текст с заданиями
    QTimer *timer; // таймер

protected:
    //void enterEvent(QEnterEvent *event) override;
};

#endif // MAINWINDOW_H
