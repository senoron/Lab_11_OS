#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>

#include "..//..//constants.h"


#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#define CountMsg 5
using namespace std;

struct json{
    double BTC;
    double ETH;
    double SOL;
    double ADA;
    double DOGE;
    double MATIC;
    double BCH;
    double LTC;

    QString update;


};



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct mystruct{
    Ui::MainWindow *ui;
    QList <json*> listJson;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:



    void on_updates_currentIndexChanged(int index);

public:
    Ui::MainWindow *ui;
    mystruct *clientStruct;
};


#endif // MAINWINDOW_H
