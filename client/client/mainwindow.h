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
    double SHIB;
    double LTC;

    QString update;


};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void init();
private:
    Ui::MainWindow *ui;
    QList <json> listJson;
};
#endif // MAINWINDOW_H
