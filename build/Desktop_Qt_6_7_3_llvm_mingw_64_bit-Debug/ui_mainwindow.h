/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *add_button;
    QGroupBox *gbox_monday;
    QFrame *frame;
    QTextBrowser *txt_tasks;
    QProgressBar *day_progress;
    QPushButton *b_toleft;
    QPushButton *b_toright;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        add_button = new QPushButton(centralwidget);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(250, 400, 93, 29));
        gbox_monday = new QGroupBox(centralwidget);
        gbox_monday->setObjectName("gbox_monday");
        gbox_monday->setGeometry(QRect(100, 50, 400, 241));
        frame = new QFrame(gbox_monday);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 30, 381, 191));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        txt_tasks = new QTextBrowser(frame);
        txt_tasks->setObjectName("txt_tasks");
        txt_tasks->setGeometry(QRect(0, 0, 381, 192));
        day_progress = new QProgressBar(gbox_monday);
        day_progress->setObjectName("day_progress");
        day_progress->setGeometry(QRect(0, 231, 443, 16));
        day_progress->setValue(24);
        b_toleft = new QPushButton(centralwidget);
        b_toleft->setObjectName("b_toleft");
        b_toleft->setGeometry(QRect(20, 180, 41, 29));
        b_toright = new QPushButton(centralwidget);
        b_toright->setObjectName("b_toright");
        b_toright->setGeometry(QRect(540, 180, 41, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        add_button->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        gbox_monday->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\275\320\265\320\264\320\265\320\273\321\214\320\275\320\270\320\272", nullptr));
        txt_tasks->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#4c3535;\">\320\241\320\265\320\263\320\276\320\264\320\275\321\217\321\210\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270:</span></p></body></html>", nullptr));
        b_toleft->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        b_toright->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
