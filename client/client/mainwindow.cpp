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
               json *lastUpdate=new json();
                cout<<("I wait\n");

            sem_wait(semptr);

            sem_getvalue(semptr , &temp);
                printf("value sem : %d\n" , temp);

                //printf("My %d msg with server : %s" , i++ + 1 , (char*)pBuf);



              // QString str="{\"detail\":{\"BTC\":57621.47,\"ETH\":4665.99,\"SOL\":213.713,\"ADA\":1.5697,\"DOGE\":0.2164,\"MATIC\":1.8208,\"SHIB\":0.0000492,\"LTC\":210.42},\"lastUpdated\":\"Tue Nov 30 2021 22:48:03 GMT+0200 (Eastern European Standard Time)\"}";//(char*)pBuf;


                // char*tt="{\"detail\":{\"BTC\":57621.47,\"ETH\":4665.99,\"SOL\":213.713,\"ADA\":1.5697,\"DOGE\":0.2164,\"MATIC\":1.8208,\"SHIB\":0.0000492,\"LTC\":210.42},\"lastUpdated\":\"Tue Nov 30 2021 22:48:03 GMT+0200 (Eastern European Standard Time)\"}";


                QString str=QString::fromUtf8((char*)pBuf);


                QJsonDocument jsondocument = QJsonDocument::fromJson(str.toUtf8());


                  lastUpdate->update=QString::fromStdString(  jsondocument.object().value("lastUpdated").toString().toStdString());

                  ui->label_update->setText(lastUpdate->update);;

               //ui->label->setText(QString::fromStdString(  jsondocument.object().value("lastUpdated").toString().toStdString()));
                QJsonObject details= jsondocument.object().value("detail").toObject();



                lastUpdate->ADA=details.value("ADA").toDouble();

                lastUpdate->BTC=details.value("BTC").toDouble();
                lastUpdate->DOGE=details.value("DOGE").toDouble();
                lastUpdate->ETH=details.value("ETH").toDouble();
                lastUpdate->LTC=details.value("LTC").toDouble();                                     //ui->label->setText(QString::number(details.value("ADA").toDouble()));
                                                                                                         // ui->lineEdit_ada->setText("  ");
                lastUpdate->MATIC=details.value("MATIC").toDouble();
                lastUpdate->SHIB=details.value("SHIB").toDouble();
                lastUpdate->SOL=details.value("SOL").toDouble();



                st->listJson.push_back(lastUpdate);

                sem_post(semptr);

                sem_getvalue(semptr , &temp);
                printf("value sem : %d\n" , temp);


               ui->lineEdit_ada->setText(QString::number(lastUpdate->ADA));
               ui->lineEdit_btc->setText(QString::number(lastUpdate->BTC));
                ui->lineEdit_doge->setText(QString::number(lastUpdate->DOGE));
                ui->lineEdit_eth->setText(QString::number(lastUpdate->ETH));
                ui->lineEdit_ltc->setText(QString::number(lastUpdate->LTC));
                ui->lineEdit_matic->setText(QString::number(lastUpdate->MATIC));
                ui->lineEdit_shib->setText(QString::number(lastUpdate->SHIB));
                ui->lineEdit_sol->setText(QString::number(lastUpdate->SOL));






               ui->updates->addItem(lastUpdate->update.split(" ")[4]);

               sleep(8);


                if(i == 5)
                   break;
            }

            close(handleFile);
            sem_close(semptr);
            shm_unlink(memoryName);


 qDebug("enter");



return 0;
}







void MainWindow::on_updates_currentIndexChanged(int index)
{


    ui->lineEdit_ada->setText(QString::number(clientStruct->listJson[index]->ADA));
    ui->lineEdit_btc->setText(QString::number(clientStruct->listJson[index]->BTC));
    ui->lineEdit_doge->setText(QString::number(clientStruct->listJson[index]->DOGE));
    ui->lineEdit_eth->setText(QString::number(clientStruct->listJson[index]->ETH));
    ui->lineEdit_ltc->setText(QString::number(clientStruct->listJson[index]->LTC));
    ui->lineEdit_matic->setText(QString::number(clientStruct->listJson[index]->MATIC));
    ui->lineEdit_shib->setText(QString::number(clientStruct->listJson[index]->SHIB));
    ui->lineEdit_sol->setText(QString::number(clientStruct->listJson[index]->SOL));


    ui->label_update->setText(clientStruct->listJson[index]->update);
}

