#include<stdio.h>
#include<stdlib.h>

int main(void){
    int* p = malloc(1024*1024*1024);
    if(p==NULL){
        printf("内存分配失败");
        return -1;
    }
    p = realloc(p,16);
    return 0;
}
