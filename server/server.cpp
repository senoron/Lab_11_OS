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

string pricesFileName = "Prices.json"; // file with all updating prices

int main()
{
    int handleFile;
    void* pBuf;

    sem_t* semptr = sem_open(semName, O_CREAT ,  0666 , 1); // creating semaphore
    int temp = -2;
    
    if(semptr == SEM_FAILED) { // failed to create the semaphore
    	printf("Error with pBuf");
    }


    handleFile = shm_open(memoryName , O_CREAT | O_RDWR , 0666); // creating sharing memory
    ftruncate(handleFile, sharedSize); // cutting file size

    pBuf = mmap(NULL , sharedSize , PROT_WRITE | PROT_READ , MAP_SHARED , handleFile , 0); // getting pointer to shring mem
    
    if(!pBuf) { // error with pointer
    	printf("Error with pBuf");
    }

    pid_t runner = fork(); // creating process for auto updating crypto currencies
    if(runner == 0){
        char* args[2];
        args[0] = ".//crypto-runner";   
        args[1] = NULL;

        execvp(args[0], args);
    }

    int i = 0;

    int longSleep = 15; // waiting for crypto to be updated
    int shortSleep = 5; // waiting for clients to read the mem

    while(1)
    {   
    	sem_wait(semptr);
    	
        sleep(longSleep);

        ifstream file; // reating from file with updated crypto
        file.open(pricesFileName);
        string str = "";
        getline(file, str);
        file.close();

        const char * mess = str.c_str(); // string to char*

      	sprintf((char*)pBuf , "%s" , mess); // writing to memory
      	
    	sem_post(semptr);
    	
    	sleep(shortSleep); // time for clients to read the memory 
    }
    
    
    close(handleFile);
    sem_close(semptr);
    shm_unlink(memoryName);
    kill(runner, 200);
}