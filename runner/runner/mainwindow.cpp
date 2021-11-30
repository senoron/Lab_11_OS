#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_run_serveer_clicked()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        qDebug() << "I am child-server";
        execvp(argvServer[0] , argvServer);
    }

    if(pid > 0)
    {
        idServer = pid;
        ui->lineEdit_state->setText(StatusServer);
    }
}


void MainWindow::on_pushButton_clicked()
{
    CountClients = ui->spinBox_clients->value();
    idClients.clear();

    for (int i = 0 ; i < CountClients ; i++ )
    {
        pid_t pid = fork();

        if(pid == 0)
        {
            qDebug() << "I am child-client";
            execvp(argvClient[0] , argvServer);
        }

        if(pid > 0)
        {
            idClients.push_back(pid);
        }
    }
}


void MainWindow::on_pushButton_filltable_clicked()
{
    ui->list_client->clear();

    for (int i = 0 ; i < CountClients ; i++ )
    {
        ui->list_client->addItem("Client " + QString :: number(i + 1) + " , id : " + QString :: number(idClients[i]));
    }
}


void MainWindow::on_pushButton_stop_clicked()
{
    for (int i = 0 ; i < CountClients ; i++ )
    {
        kill(idClients[i] , SIGKILL);
    }

    if(idServer != -1)
    {
        kill(idServer , SIGKILL);
    }

    CountClients = 0;
    idClients.clear();
    StatusServer = "Killed";

    ui->lineEdit_state->setText(StatusServer);
}

