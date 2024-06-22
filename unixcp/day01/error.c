#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main(void){
    //int*p = malloc(0xffffffffffffffff);
    //if(p == NULL){
      //  printf("errno=%d\n",errno);
      //  printf("errno=%s\n",strerror(errno));//将错误码转换成对应的错误
      //  perror("内存满了");
        //return -1;
    //}
    //free(p);
    //p == NULL;
    FILE* fp = fopen("env","r");
    if(fp == NULL){
        perror("fopen");
        return -1;
    }
}
