/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit_state;
    QSpinBox *spinBox_clients;
    QLabel *label_2;
    QLabel *label_clients;
    QTextEdit *textEdit_clients;
    QPushButton *pushButton_run_serveer;
    QPushButton *pushButton_stop;
    QPushButton *pushButton;
    QPushButton *pushButton_filltable;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(561, 281);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 255, 253);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 60, 51, 21));
        lineEdit_state = new QLineEdit(centralwidget);
        lineEdit_state->setObjectName(QString::fromUtf8("lineEdit_state"));
        lineEdit_state->setGeometry(QRect(340, 60, 113, 20));
        spinBox_clients = new QSpinBox(centralwidget);
        spinBox_clients->setObjectName(QString::fromUtf8("spinBox_clients"));
        spinBox_clients->setGeometry(QRect(10, 61, 42, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 60, 111, 21));
        label_clients = new QLabel(centralwidget);
        label_clients->setObjectName(QString::fromUtf8("label_clients"));
        label_clients->setGeometry(QRect(10, 110, 71, 16));
        textEdit_clients = new QTextEdit(centralwidget);
        textEdit_clients->setObjectName(QString::fromUtf8("textEdit_clients"));
        textEdit_clients->setGeometry(QRect(10, 140, 221, 111));
        pushButton_run_serveer = new QPushButton(centralwidget);
        pushButton_run_serveer->setObjectName(QString::fromUtf8("pushButton_run_serveer"));
        pushButton_run_serveer->setGeometry(QRect(290, 10, 91, 31));
        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(330, 220, 91, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 91, 31));
        pushButton_filltable = new QPushButton(centralwidget);
        pushButton_filltable->setObjectName(QString::fromUtf8("pushButton_filltable"));
        pushButton_filltable->setGeometry(QRect(330, 140, 91, 31));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">State:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">number of clients</span></p></body></html>", nullptr));
        label_clients->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Clients:</span></p></body></html>", nullptr));
        pushButton_run_serveer->setText(QCoreApplication::translate("MainWindow", "Run Server", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Run Clients", nullptr));
        pushButton_filltable->setText(QCoreApplication::translate("MainWindow", "Fill Table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
