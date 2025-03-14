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
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;

    void setupUi(QDialog *Add_task)
    {
        if (Add_task->objectName().isEmpty())
            Add_task->setObjectName("Add_task");
        Add_task->resize(415, 204);
        gridLayout_2 = new QGridLayout(Add_task);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(Add_task);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(Add_task);
        lineEdit->setObjectName("lineEdit");

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 3);

        pushButton = new QPushButton(Add_task);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(Add_task);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(Add_task);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(Add_task);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(pushButton_7, 1, 3, 1, 1);

        pushButton_4 = new QPushButton(Add_task);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(Add_task);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(Add_task);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(pushButton_6, 2, 2, 1, 1);

        pushButton_8 = new QPushButton(Add_task);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setMinimumSize(QSize(0, 29));

        gridLayout_2->addWidget(pushButton_8, 2, 3, 1, 1);


        retranslateUi(Add_task);

        QMetaObject::connectSlotsByName(Add_task);
    } // setupUi

    void retranslateUi(QDialog *Add_task)
    {
        Add_task->setWindowTitle(QCoreApplication::translate("Add_task", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Add_task", "\320\242\320\262\320\276\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Add_task", "\320\237\320\275", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Add_task", "\320\222\321\202", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Add_task", "\320\241\321\200", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Add_task", "\320\247\321\202", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Add_task", "\320\237\321\202", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Add_task", "\320\241\320\261", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Add_task", "\320\235\320\264", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Add_task", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_task: public Ui_Add_task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_TASK_H
