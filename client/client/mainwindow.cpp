#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

void* client( void* Mystruct);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    pthread_t HANDLE;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    ui->setupUi(this);

    clientStruct=new mystruct();
    clientStruct->ui=ui;



    pthread_create(&HANDLE,& attr,client,(void*)clientStruct);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void* client( void* Mystruct)
{
    qDebug("enter");
    mystruct *st= (mystruct*)(Mystruct);

    Ui::MainWindow *ui=st->ui;



    int handleFile;
            void* pBuf;

            sem_t* semptr = sem_open(semName, O_CREAT ,  0666 , 0);
            int temp = -2;

            sem_getvalue(semptr , &temp);
            printf("value sem : %d\n" , temp);

            handleFile = shm_open(memoryName , O_RDWR , 0666);
            pBuf = mmap(NULL , sharedSize , PROT_WRITE | PROT_READ , MAP_SHARED , handleFile , 0);

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

                st->listJson.push_back(lastUpdate);

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
            shm_unlink(memoryName);







}







void MainWindow::on_updates_currentIndexChanged(int index)
{


    ui->lineEdit_ada->setText(QString::number(clientStruct->listJson[index].ADA));
    ui->lineEdit_btc->setText(QString::number(clientStruct->listJson[index].BTC));
    ui->lineEdit_doge->setText(QString::number(clientStruct->listJson[index].DOGE));
    ui->lineEdit_eth->setText(QString::number(clientStruct->listJson[index].ETH));
    ui->lineEdit_ltc->setText(QString::number(clientStruct->listJson[index].LTC));
    ui->lineEdit_matic->setText(QString::number(clientStruct->listJson[index].MATIC));
    ui->lineEdit_shib->setText(QString::number(clientStruct->listJson[index].SHIB));
    ui->lineEdit_sol->setText(QString::number(clientStruct->listJson[index].SOL));


    ui->label_update->setText(clientStruct->listJson[index].update);
}

