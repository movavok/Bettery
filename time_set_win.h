#ifndef TIME_SET_WIN_H
#define TIME_SET_WIN_H

#include <QDialog>
#include <QSlider>
#include <QLCDNumber>

namespace Ui {
class time_set_win;
}

class time_set_win : public QDialog
{
    Q_OBJECT

public:
    explicit time_set_win(QWidget *parent = nullptr);
    ~time_set_win();

private slots:
    void on_pushButton_clicked();

private:
    Ui::time_set_win *ui;
};

#endif // TIME_SET_WIN_H
