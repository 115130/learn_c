#include<stdio.h>
int main(void){
    int second = 0;
    printf("请输入秒数");
    scanf("%d",&second);
    int temp = second;
    int m = 0, h = 0;
    h = second / 3600;
    second = second % 3600;
    m = second / 60;
    second = second % 60;
    printf("%d秒转换后是%d时%d分%d秒",temp,h,m,second);

}
