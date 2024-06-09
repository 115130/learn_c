#include<stdio.h>
#include<stdlib.h>
int main(void){
    unsigned long size = 4ul*1024*1024*1024*3;
    int *p = malloc(size);
    for (unsigned long i = 0;i< size/4;i++){
        p[i]=i;
    }
    while(1);
    return 0;
}
