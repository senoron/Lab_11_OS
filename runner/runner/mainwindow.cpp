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


void MainWindow::on_pushButton_stop_clicked()
{

}


void MainWindow::on_pushButton_run_serveer_clicked()
{
    pid_t pid = fork();

    if(pid == 0)
    {

        qDebug() << "I am child";
        execvp(argvServer[0] , argvServer);
    }

    if(pid > 0)
    {
        idServer = pid;
        //kill(idServer , SIGKILL);
        sleep(2);
        //StatusServer = QString :: number(pid);
        ui->lineEdit_state->setText(StatusServer);
                //kill(idServer , SIGKILL);

    }
}

