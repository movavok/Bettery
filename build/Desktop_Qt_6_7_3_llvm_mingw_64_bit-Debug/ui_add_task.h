/********************************************************************************
** Form generated from reading UI file 'add_task.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_TASK_H
#define UI_ADD_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Add_task
{
public:
    QGridLayout *gridLayout_2;
    QLabel *lb_yourtask;
    QLineEdit *le_task;
    QPushButton *b_pickMon;
    QPushButton *b_pickTue;
    QPushButton *b_pickWed;
    QPushButton *b_pickThu;
    QPushButton *b_pickFri;
    QPushButton *b_pickSat;
    QPushButton *b_pickSun;
    QPushButton *b_ready;

    void setupUi(QDialog *Add_task)
    {
        if (Add_task->objectName().isEmpty())
            Add_task->setObjectName("Add_task");
        Add_task->resize(415, 204);
        gridLayout_2 = new QGridLayout(Add_task);
        gridLayout_2->setObjectName("gridLayout_2");
        lb_yourtask = new QLabel(Add_task);
        lb_yourtask->setObjectName("lb_yourtask");

        gridLayout_2->addWidget(lb_yourtask, 0, 0, 1, 1);

        le_task = new QLineEdit(Add_task);
        le_task->setObjectName("le_task");

        gridLayout_2->addWidget(le_task, 0, 1, 1, 3);

        b_pickMon = new QPushButton(Add_task);
        b_pickMon->setObjectName("b_pickMon");
        b_pickMon->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(b_pickMon, 1, 0, 1, 1);

        b_pickTue = new QPushButton(Add_task);
        b_pickTue->setObjectName("b_pickTue");
        b_pickTue->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(b_pickTue, 1, 1, 1, 1);

        b_pickWed = new QPushButton(Add_task);
        b_pickWed->setObjectName("b_pickWed");
        b_pickWed->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(b_pickWed, 1, 2, 1, 1);

        b_pickThu = new QPushButton(Add_task);
        b_pickThu->setObjectName("b_pickThu");
        b_pickThu->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(b_pickThu, 1, 3, 1, 1);

        b_pickFri = new QPushButton(Add_task);
        b_pickFri->setObjectName("b_pickFri");
        b_pickFri->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(b_pickFri, 2, 0, 1, 1);

        b_pickSat = new QPushButton(Add_task);
        b_pickSat->setObjectName("b_pickSat");
        b_pickSat->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(b_pickSat, 2, 1, 1, 1);

        b_pickSun = new QPushButton(Add_task);
        b_pickSun->setObjectName("b_pickSun");
        b_pickSun->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(b_pickSun, 2, 2, 1, 1);

        b_ready = new QPushButton(Add_task);
        b_ready->setObjectName("b_ready");
        b_ready->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(b_ready, 2, 3, 1, 1);


        retranslateUi(Add_task);

        QMetaObject::connectSlotsByName(Add_task);
    } // setupUi

    void retranslateUi(QDialog *Add_task)
    {
        Add_task->setWindowTitle(QCoreApplication::translate("Add_task", "Dialog", nullptr));
        lb_yourtask->setText(QCoreApplication::translate("Add_task", "\320\242\320\262\320\276\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
        b_pickMon->setText(QCoreApplication::translate("Add_task", "\320\237\320\275", nullptr));
        b_pickTue->setText(QCoreApplication::translate("Add_task", "\320\222\321\202", nullptr));
        b_pickWed->setText(QCoreApplication::translate("Add_task", "\320\241\321\200", nullptr));
        b_pickThu->setText(QCoreApplication::translate("Add_task", "\320\247\321\202", nullptr));
        b_pickFri->setText(QCoreApplication::translate("Add_task", "\320\237\321\202", nullptr));
        b_pickSat->setText(QCoreApplication::translate("Add_task", "\320\241\320\261", nullptr));
        b_pickSun->setText(QCoreApplication::translate("Add_task", "\320\235\320\264", nullptr));
        b_ready->setText(QCoreApplication::translate("Add_task", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_task: public Ui_Add_task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_TASK_H
