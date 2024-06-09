#include<stdio.h>
int main(void){
    int num = 0;
    printf("请输入一个三位的整数\n");
    scanf("%d",&num);
    int temp = num;
    int unit = num%10;
    num = num/10;
    int digit = num%10;
    num = num / 10;
    
    printf("%d的百位是%d,十位是%d,个位是%d\n",temp,num,digit,unit);
}
