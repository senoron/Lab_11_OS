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





            sem_post(semptr);

            sem_getvalue(semptr , &temp);
            printf("value sem : %d\n" , temp);

            sleep(8);

            if(i == 5)
                break;
        }

        //close(handleFile);
        sem_close(semptr);
        shm_unlink("file");


}
