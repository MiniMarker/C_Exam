#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <crypt.h>
#include <string.h>

#include <unistd.h>

struct threadInfo {
    pthread_t   thread_id;
    int         num;
    char        *testString;
    int         iterations;
} threadInfo;

const long numberOfThreads = 2;
const int array[10] = {1,2,3,4,5,6,7,8,9,0};

pthread_mutex_t mutex;

void* task(void *thread_struct) {

    struct threadInfo *tinfo = thread_struct;

    for(int i = (tinfo->num * 5); i < (tinfo->num + 5); i++){
        printf("Thread %d: %d\n", tinfo->num, array[i]);
    }
    
    /*
    //Lock the thread
    pthread_mutex_lock(&mutex);
    
    sleep(1);
    printf("Message from thread %d: %s\n", tinfo->num, tinfo->testString);
    
    pthread_mutex_unlock(&mutex);
    */
    
}

int main(int argc,char** argv){

    int             success;
    struct          threadInfo *tinfo;
    pthread_attr_t  attr;
    
    pthread_attr_init(&attr);                   
    pthread_mutex_init(&mutex, NULL);           // Init mutex (lock)

    tinfo = calloc(numberOfThreads, sizeof(struct threadInfo));
    
    for(int i = 0; i < numberOfThreads; ++i) {

        tinfo[i].num = i;
        tinfo[i].testString = "Hello from Struct";
        tinfo[i].iterations = 5;

        success = pthread_create(&tinfo[i].thread_id, &attr, &task, &tinfo[i]);

        if (success != 0) {
            printf("ERROR: Unable to create worker thread %ld successfully\n",i);
            pthread_mutex_destroy(&mutex);
            return 1;
        }

    }

    for(int i = 0; i<numberOfThreads; ++i) {
        pthread_join(tinfo[i].thread_id,NULL);
    }

    free(tinfo);

    pthread_mutex_destroy(&mutex);

    return 0;
}