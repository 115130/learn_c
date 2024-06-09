#include<stdio.h>
int main(void){
    char i = 0;
    printf("接下来本程序将会读取一个数字,并把数字转换为二进制输出");
    scanf("%hhd",&i);
    int p = 1;
    int size = sizeof(i) * 8;
    char arr[size] ;
    
    for(int t = size-1;t>=0;t--){
        p *= 2;
        arr[t]=i & p ? '1' : '0';
    }
    p = 0;
    for(int t = 0;t<size;t++){
        
        printf("%c",arr[t]); 
        p++;
        if(p%4==0){
            printf(" ");
        }
        
    }

    
    return 0;
}
