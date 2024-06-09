#include<stdio.h>
#include<stdlib.h>
int main(void){
    int *p = calloc(10,sizeof(int));
    if(p==NULL){
        printf("内存分配失败");
        return 0;
    }
    for(int i = 0;i < 10;i++){
        printf("%d",*(p+i));
        printf("\n");
        *(p+i) = 100 + i;
    }
    for(int i = 0;i < 10;i++){
        printf("%d ",*(p+i));
    }
    free(p);
    p = NULL;
    return 0;
}
