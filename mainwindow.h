#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_button_clicked();
    void day_progress();

private:
    Ui::MainWindow *ui;

    QTimer *timer; // таймер
};
#endif // MAINWINDOW_H
