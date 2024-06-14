#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void){
    int* p = (int*)malloc(0xffffffffffffffff);    
    //if(p == NULL){
      //  printf("errno=%d\n",errno);
        //printf("errno=%s\n",strerror(errno));
        //perror("内存满了");
        //return -1;
    //}
    //free(p);
    //p = NULL;
    FILE* fp = fopen("env","r");
    if(errno != 0){
        perror("fopen");
        return -1;
    }

    return 0;
}
