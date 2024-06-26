#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#define PI 3.14

//double c =  0;

void* area(void* arg){
    double r = *(double*)arg;
    static double t = 0;
    t = (PI*r*r);
    return (void*)&t;
    
}


int main(void){
    double r =10;
    pthread_t tid;
    tid = pthread_create(&tid,NULL,area,&r);
    double *t;
    pthread_join(tid,(void**)&t);

    printf("圆的面积是%lg\n",r);

    return 0;
}
