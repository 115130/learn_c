#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

void* ave(void* arg){
    double *d = (double*)arg; 
    d[2]=((d[0]+d[1])/2);
    return NULL;
}

int main(void){
    double data[3] = {4,8};
    pthread_t tid;
    pthread_create(&tid,NULL,ave,&data);
    pthread_join(tid,NULL);
    for(int i = 0;i < (sizeof(data)/sizeof(data[0]));i++){
        printf("%g ",data[i]);
    }

    return 0;
}
