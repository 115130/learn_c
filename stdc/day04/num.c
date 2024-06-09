#include<stdio.h>
int main(void){
    int num = 0;
    printf("请输入一个整数:");
    scanf("%d",&num);
    printf("%d有",num);
    int i;
    do{
        i++;
    }while((num=num/10)!=0);
    printf("%d位",i);
    return 0;
}
