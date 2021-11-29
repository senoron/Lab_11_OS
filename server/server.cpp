#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <fstream>
#include <iostream>

#include "constants.h"

using namespace std;

string pricesFileName = "Prices.json";

int main()
{
    int handleFile;
    void* pBuf;

    sem_t* semptr = sem_open(semName, O_CREAT ,  0666 , 1);
    int temp = -2;
    
    if(semptr == SEM_FAILED) {
    	printf("Error with pBuf");
    }


    handleFile = shm_open(memoryName , O_CREAT | O_RDWR , 0666);
    ftruncate(handleFile, sharedSize);

    pBuf = mmap(NULL , sharedSize , PROT_WRITE | PROT_READ , MAP_SHARED , handleFile , 0);
    
    if(!pBuf) {
    	printf("Error with pBuf");
    }

    //system("node ../crypto-loader/index.js");
    int i = 0;
    while(1)
    {
        printf("I go\n");
        
    	sem_wait(semptr);
    	
    	printf("I some sleep\n");
    	
    	sem_getvalue(semptr , &temp);
        printf("value sem : %d\n" , temp);
        
        sleep(30);

    	printf("I slept\n");
    	
        ifstream file;
        file.open("Prices.json");
        string str = "";
        getline(file, str);
        cout << str.size() << endl;
        cout << str << endl;
        file.close();

        const char * mess = str.c_str();

      	sprintf((char*)pBuf , "%s" , mess);
      		
      	printf("I send date\n");
      	
    	sem_post(semptr);
    	
    	sem_getvalue(semptr , &temp);
    	printf("value sem : %d\n" , temp);
    	sleep(3);
    	
    }
    
    
    close(handleFile);
    sem_close(semptr);
    shm_unlink("file");
}