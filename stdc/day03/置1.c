#include<stdio.h>
int main(void){
    char i = 0;
    printf("请输入数字,本程序会把输入数字高四位不变,低四位置1\n");
    scanf("%hhd", &i);
    i |= 15;
    printf("处理过后的数据为%hhd",i);
}
