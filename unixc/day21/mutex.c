#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<pthread.h>
volatile int g_cn = 0;

pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;


void* add(void* arg){
    pthread_mutex_lock(&mutex);
    for(int i = 0; i<100000;i++){
        g_cn++;
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(void){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,add,NULL);
    pthread_create(&t2,NULL,add,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("%d",g_cn);;
}
