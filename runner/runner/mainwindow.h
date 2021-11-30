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

private:
    Ui::MainWindow *ui;
    int CountClients;
    pid_t idServer;
    QString StatusServer = "Running";
    char* argvServer[2] = {"//home//volframiy//NewLab04//a.out" , NULL};
    QString WayToClient = "//hoem//Desktop//Lab11_OS//client";
};
#endif // MAINWINDOW_H
