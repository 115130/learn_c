#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    int arr[6]={};
    int  length = sizeof(arr)/sizeof(arr[0]);
    srand(time(NULL));
    for(int i = 0;i < length;i++){
        while(1){
            int num = rand() % 33 + 1;
            for(int j = 0; j < length; j++){
                if(arr[j] == num){
                    continue;
                }
                arr[i]=num;
                break;
            }
        }
    } 
    printf("红球是:");
    for(int i = 0;i < length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n蓝球是:%d",rand()%16+1);
    return 0;
}
