#include<stdio.h>
int main(void){
    FILE* fp = fopen("./nvim.txt","a");
    if(fp == NULL){
        printf("文件为空");
        return -1;
    }

    fclose(fp);
    return 0;
}
