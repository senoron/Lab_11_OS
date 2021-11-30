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
    float BTC;
    float ETH;
    float SOL;
    float ADA;
    float DOGE;
    float MATIC;
    float SHIB;
    float LTC;

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
};
#endif // MAINWINDOW_H
