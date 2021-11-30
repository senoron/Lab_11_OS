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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_update;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_ltc;
    QLineEdit *lineEdit_eth;
    QLabel *label_matic;
    QLabel *label_ltc;
    QLabel *label_eth;
    QLabel *label_ada;
    QLabel *label_shib;
    QLineEdit *lineEdit_ada;
    QLineEdit *lineEdit_doge;
    QLineEdit *lineEdit_btc;
    QLabel *label_sol;
    QLineEdit *lineEdit_shib;
    QLineEdit *lineEdit_sol;
    QLineEdit *lineEdit_matic;
    QLabel *label_doge;
    QLabel *label_btc;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(567, 453);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 255, 253);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 51, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 10, 91, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 380, 101, 21));
        label_update = new QLabel(centralwidget);
        label_update->setObjectName(QString::fromUtf8("label_update"));
        label_update->setGeometry(QRect(140, 380, 161, 21));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 40, 261, 281));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_ltc = new QLineEdit(widget);
        lineEdit_ltc->setObjectName(QString::fromUtf8("lineEdit_ltc"));

        gridLayout->addWidget(lineEdit_ltc, 7, 1, 1, 1);

        lineEdit_eth = new QLineEdit(widget);
        lineEdit_eth->setObjectName(QString::fromUtf8("lineEdit_eth"));

        gridLayout->addWidget(lineEdit_eth, 1, 1, 1, 1);

        label_matic = new QLabel(widget);
        label_matic->setObjectName(QString::fromUtf8("label_matic"));

        gridLayout->addWidget(label_matic, 5, 0, 1, 1);

        label_ltc = new QLabel(widget);
        label_ltc->setObjectName(QString::fromUtf8("label_ltc"));

        gridLayout->addWidget(label_ltc, 7, 0, 1, 1);

        label_eth = new QLabel(widget);
        label_eth->setObjectName(QString::fromUtf8("label_eth"));

        gridLayout->addWidget(label_eth, 1, 0, 1, 1);

        label_ada = new QLabel(widget);
        label_ada->setObjectName(QString::fromUtf8("label_ada"));

        gridLayout->addWidget(label_ada, 3, 0, 1, 1);

        label_shib = new QLabel(widget);
        label_shib->setObjectName(QString::fromUtf8("label_shib"));

        gridLayout->addWidget(label_shib, 6, 0, 1, 1);

        lineEdit_ada = new QLineEdit(widget);
        lineEdit_ada->setObjectName(QString::fromUtf8("lineEdit_ada"));

        gridLayout->addWidget(lineEdit_ada, 3, 1, 1, 1);

        lineEdit_doge = new QLineEdit(widget);
        lineEdit_doge->setObjectName(QString::fromUtf8("lineEdit_doge"));

        gridLayout->addWidget(lineEdit_doge, 4, 1, 1, 1);

        lineEdit_btc = new QLineEdit(widget);
        lineEdit_btc->setObjectName(QString::fromUtf8("lineEdit_btc"));

        gridLayout->addWidget(lineEdit_btc, 0, 1, 1, 1);

        label_sol = new QLabel(widget);
        label_sol->setObjectName(QString::fromUtf8("label_sol"));

        gridLayout->addWidget(label_sol, 2, 0, 1, 1);

        lineEdit_shib = new QLineEdit(widget);
        lineEdit_shib->setObjectName(QString::fromUtf8("lineEdit_shib"));

        gridLayout->addWidget(lineEdit_shib, 6, 1, 1, 1);

        lineEdit_sol = new QLineEdit(widget);
        lineEdit_sol->setObjectName(QString::fromUtf8("lineEdit_sol"));

        gridLayout->addWidget(lineEdit_sol, 2, 1, 1, 1);

        lineEdit_matic = new QLineEdit(widget);
        lineEdit_matic->setObjectName(QString::fromUtf8("lineEdit_matic"));

        gridLayout->addWidget(lineEdit_matic, 5, 1, 1, 1);

        label_doge = new QLabel(widget);
        label_doge->setObjectName(QString::fromUtf8("label_doge"));

        gridLayout->addWidget(label_doge, 4, 0, 1, 1);

        label_btc = new QLabel(widget);
        label_btc->setObjectName(QString::fromUtf8("label_btc"));

        gridLayout->addWidget(label_btc, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 567, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Name</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Rate</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Last update:</span></p></body></html>", nullptr));
        label_update->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>_________________________</p></body></html>", nullptr));
        label_matic->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">MATIC</span></p></body></html>", nullptr));
        label_ltc->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">LTC</span></p></body></html>", nullptr));
        label_eth->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">ETH</span></p></body></html>", nullptr));
        label_ada->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">ADA</span></p></body></html>", nullptr));
        label_shib->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">SHIB</span></p></body></html>", nullptr));
        label_sol->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">SOL</span></p></body></html>", nullptr));
        label_doge->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">DOGE</span></p></body></html>", nullptr));
        label_btc->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">BTC</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
