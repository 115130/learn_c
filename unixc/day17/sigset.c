#include <bits/types/sigset_t.h>
#include<time.h>
#include<stdio.h>
#include<signal.h>
//打印一个字节的二进制
void printfb(char byte){ 
    for(int i = 8;i>=1;i--){

        printf("%d",byte & (1<<(i-1)) ?1:0);
    } 
    printf("  ");
}
//打印所有字节的二进制
void printm(void* buf,size_t size){
    char* bufc = (char*)buf;
    for(int i = 0; i < size; i++){
       printfb(bufc[size-1-i]);
       if((i+1) % 8 == 0){
            printf("\n");
       }
    }
}

int main(void){
    sigset_t set;
    sigfillset(&set);
    printm(&set,sizeof(set));
    return 0;
}

