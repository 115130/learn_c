#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#define PI 3.14


void* area(void* arg){
    double r = *(double*)arg;
    double *t = malloc(sizeof(double));
    *t = (PI*r*r);
    return (void*)t;
}


int main(void){
    double r =10;
    pthread_t tid;
    pthread_create(&tid,NULL,area,&r);
    if( tid == -1){
        perror("pthread_create");
        return -1;
    }
    double *t = NULL;
   
    double r2 =20;
    pthread_t tid2;
    pthread_create(&tid2,NULL,area,&r2);
    if(tid2 == -1){
        perror("pthread_create");
        return -1;
    }
    double *t2 = NULL; 


    pthread_join(tid,(void**)&t);
    printf("圆的面积是%lg\n",*t);

    pthread_join(tid2,(void**)&t2);
    printf("圆的面积是%lg\n",*t2);
    free(t);
    free(t2);
    return 0;
}
