#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fstream>

using namespace std;

string pricesFileName = "Prices.json";
pid_t runner;
sem_t* semptr;
int handleFile;

void* server( void* Mystruct);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    runner = fork(); // creating process for auto updating crypto currencies
    if(runner == 0){
        char* args[2];
        args[0] = "..//..//server//crypto-runner";
        args[1] = NULL;

        execvp(args[0], args);
    }

    pthread_t HANDLE;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&HANDLE,& attr, server, NULL);
}

MainWindow::~MainWindow()
{
    kill(runner, 200);
    sem_close(semptr);
    shm_unlink(memoryName);
    delete ui;
}

void* server( void* Mystruct)
{
        void* pBuf;

        semptr = sem_open(semName, O_CREAT ,  0666 , 1); // creating semaphore
        int temp = -2;

        sem_getvalue(semptr , &temp);
        printf("value sem : %d\n" , temp);

        if(semptr == SEM_FAILED) { // failed to create the semaphore
            printf("Error with pBuf");
        }


        handleFile = shm_open(memoryName , O_CREAT | O_RDWR , 0666); // creating sharing memory
        ftruncate(handleFile, sharedSize); // cutting file size

        pBuf = mmap(NULL , sharedSize , PROT_WRITE | PROT_READ , MAP_SHARED , handleFile , 0); // getting pointer to shring mem

        if(!pBuf) { // error with pointer
            printf("Error with pBuf");
        }

        int i = 0;

        int longSleep = 15; // waiting for crypto to be updated
        int shortSleep = 5; // waiting for clients to read the mem

        while(1)
        {
            sem_wait(semptr);

            sem_getvalue(semptr , &temp);
            printf("value sem : %d\n" , temp);

            sleep(longSleep);

            ifstream file; // reating from file with updated crypto
            file.open(pricesFileName);
            string str = "";
            getline(file, str);
            file.close();

            printf("Writing info to clients");

            const char * mess = str.c_str(); // string to char*

            sprintf((char*)pBuf , "%s" , mess); // writing to memory

            sem_post(semptr);

            sem_getvalue(semptr , &temp);
            printf("value sem : %d\n" , temp);

            sleep(shortSleep); // time for clients to read the memory
        }


        close(handleFile);
}
