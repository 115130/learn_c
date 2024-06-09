#include <stdlib.h>
#include<stdio.h>
int main(void){
    FILE* fp = fopen("./out","r");
    if(fp == NULL){
        printf("打开文件失败");
        return -1;
    }

    char* arr = malloc(900);
    fscanf(fp,"%s",arr);
    printf("%s",arr);
    fclose(fp);
    fp = NULL;
    return 0;
}
