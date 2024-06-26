#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#define PI 3.14

//double c =  0;

void* area(void* arg){
    double r = *(double*)arg;
    *(double*)arg=PI*r*r;
    return NULL;
}

void* ave(void* arg){
    double *d = (double*)arg; 
    d[2]=((d[0]+d[1])/2);
    return arg;
}

int main(void){
    double r =10;
    pthread_t tid;
    pthread_create(&tid,NULL,area,&r);
    sleep(1);
    // printf("圆的面积是%lg\n",c);
    printf("圆的面积是%lg\n",r);

    double data[3] = {4,8};
    int tid1 = pthread_create(&tid,NULL,ave,&data);
    
    void *t;
    pthread_join(tid1,(void*)&t);
    for(int i = 0;i < (sizeof(data)/sizeof(data[0]));i++){
        printf("%g ",data[i]);
    }


    return 0;
}
