#include "time_set_win.h"
#include "ui_time_set_win.h"

int firsttime = 9;
int secondtime = 23;

time_set_win::time_set_win(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::time_set_win)
{
    ui->setupUi(this);
    ui->sld_firsttime->setValue(firsttime);
    ui->sld_secondtime->setValue(secondtime);

    ui->lcd_firsttime->display(firsttime);
    ui->lcd_secondtime->display(secondtime);

    connect(ui->sld_firsttime, &QSlider::valueChanged, ui->lcd_firsttime, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
    connect(ui->sld_secondtime, &QSlider::valueChanged, ui->lcd_secondtime, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));
}

time_set_win::~time_set_win()
{
    delete ui;
}

void time_set_win::on_pushButton_clicked()
{
    firsttime = ui->sld_firsttime->value();
    secondtime = ui->sld_secondtime->value();

    emit give_time(firsttime, secondtime);
    hide();
}

