#include "time_set_win.h"
#include "ui_time_set_win.h"

time_set_win::time_set_win(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::time_set_win)
{
    ui->setupUi(this);

    connect(ui->sld_firsttime, &QSlider::valueChanged, ui->lcd_firsttime, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
    connect(ui->sld_secondtime, &QSlider::valueChanged, ui->lcd_secondtime, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
}

time_set_win::~time_set_win()
{
    delete ui;
}

void time_set_win::on_pushButton_clicked()
{
    hide();
}

