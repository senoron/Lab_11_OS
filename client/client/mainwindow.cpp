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

void MainWindow::init(){
    int handleFile;
        void* pBuf;
        const int size = 256;
        sem_t* semptr = sem_open("sem", O_CREAT ,  0666 , 0);
        int temp = -2;

        sem_getvalue(semptr , &temp);
        printf("value sem : %d\n" , temp);

        handleFile = shm_open("file" , O_RDWR , 0666);

        pBuf = mmap(NULL , size , PROT_WRITE | PROT_READ , MAP_SHARED , handleFile , 0);

        int i = 0;
        while(1)
        {
           json lastUpdate;
            cout<<("I wait\n");

        sem_wait(semptr);

        sem_getvalue(semptr , &temp);
            printf("value sem : %d\n" , temp);

            printf("My %d msg with server : %s" , i++ + 1 , (char*)pBuf);
            char* str=(char*)pBuf;

            QJsonDocument jsondocument = QJsonDocument::fromJson(str);

            QJsonObject details= jsondocument.object().value("detail").toObject();

            lastUpdate.ADA=details.value("ADA").toDouble();
            lastUpdate.BTC=details.value("BTC").toDouble();
            lastUpdate.DOGE=details.value("DOGE").toDouble();
            lastUpdate.ETH=details.value("ETH").toDouble();
            lastUpdate.LTC=details.value("LTC").toDouble();
            lastUpdate.MATIC=details.value("MATIC").toDouble();
            lastUpdate.SHIB=details.value("SHIB").toDouble();
            lastUpdate.SOL=details.value("SOL").toDouble();

            lastUpdate.update=details.value("lastUpdated").toString();

            listJson.push_back(lastUpdate);

            sem_post(semptr);

            sem_getvalue(semptr , &temp);
            printf("value sem : %d\n" , temp);


            ui->lineEdit_ada->setText(QString::number(lastUpdate.ADA));
            ui->lineEdit_btc->setText(QString::number(lastUpdate.BTC));
            ui->lineEdit_doge->setText(QString::number(lastUpdate.DOGE));
            ui->lineEdit_eth->setText(QString::number(lastUpdate.ETH));
            ui->lineEdit_ltc->setText(QString::number(lastUpdate.LTC));
            ui->lineEdit_matic->setText(QString::number(lastUpdate.MATIC));
            ui->lineEdit_shib->setText(QString::number(lastUpdate.SHIB));
            ui->lineEdit_sol->setText(QString::number(lastUpdate.SOL));


            ui->label_update->setText(lastUpdate.update);


            ui->updates->addItem((lastUpdate.update.split(" "))[4]);
            sleep(8);


            if(i == 5)
                break;
        }

        //close(handleFile);
        sem_close(semptr);
        shm_unlink("file");


}




void MainWindow::on_updates_currentIndexChanged(int index)
{

    ui->lineEdit_ada->setText(QString::number(listJson[index].ADA));
    ui->lineEdit_btc->setText(QString::number(listJson[index].BTC));
    ui->lineEdit_doge->setText(QString::number(listJson[index].DOGE));
    ui->lineEdit_eth->setText(QString::number(listJson[index].ETH));
    ui->lineEdit_ltc->setText(QString::number(listJson[index].LTC));
    ui->lineEdit_matic->setText(QString::number(listJson[index].MATIC));
    ui->lineEdit_shib->setText(QString::number(listJson[index].SHIB));
    ui->lineEdit_sol->setText(QString::number(listJson[index].SOL));


    ui->label_update->setText(listJson[index].update);
}

