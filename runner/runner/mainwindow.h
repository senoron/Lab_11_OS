#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/times.h>
#include <time.h>
#include<sys/wait.h>
#include<signal.h>
#include<sys/resource.h>
#include "vector"

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
    void on_pushButton_stop_clicked();

    void on_pushButton_run_serveer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_filltable_clicked();

private:
    Ui::MainWindow *ui;

    int CountClients = 0;
    pid_t idServer = -1;
    std::vector<pid_t> idClients;

    QString StatusServer = "Running";

    char* argvServer[2] = {"//home//volframiy//Desktop//Lab11_OS//Lab11_OS//server//server" , NULL};
    char* argvClient[2] = {"////home//volframiy//Desktop//Lab11_OS//Lab11_OS//client//client//" , NULL};
};
#endif // MAINWINDOW_H
