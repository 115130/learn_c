#include<stdio.h>
int main(void){
    int arr[10] = {};
    int length = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < length; i++){
        printf("请输入第%d个数字",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i = length; i > 0; i--){
        printf("第%d个数字是%d\n",i,arr[i-1]);
    }

    
    return 0;
}
