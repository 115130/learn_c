#include<stdio.h>
int main(void){
    int year = 0;
    printf("请输入一个年数,本程序会判断输入的年是不是闰年\n");
    scanf("%d",&year);
    if (year % 400 == 0 || year%4==0&&year%100!=0){
        printf("%d是闰年",year);
    }else{
        printf("%d不是闰年",year);
    }
    return 0;
}
