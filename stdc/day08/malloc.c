#include<stdio.h>
#include<stdlib.h>

int main(void){
    int* p = malloc(8);
    if(p == NULL){
        printf("内存分配失败\n");
        return -1;
    } 
    *p = 10;
    *(p + 1) = 20;
    printf("%d %d\n",p[0],p[1]);
    free(p);
    p = NULL;
    printf("%d %d\n",p[0],p[1]);
    return 0;
}
