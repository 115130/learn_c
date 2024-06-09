#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    int arr[6]={};
    
    int length = sizeof(arr)/sizeof(arr[0]); 
    srand(time(NULL));

    for(int i = 0;i < length;i++){
        int num = 0;
        int flag = 0;
        do{
            flag = 0;
            num = rand() % 33 + 1;
            for(int j = 0; j < length; j++){
                if(arr[j] == num){
                    flag = 1;
                    break;//重复元素不再检查,直接跳出
                }
            }
        }while(flag);//没有重复循环不继续

        arr[i]=num;
    } 
    printf("红球是:");
    for(int i = 0;i < length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n蓝球是:%d",rand()%16+1);
    return 0;
}
