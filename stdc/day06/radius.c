#include<stdio.h>
#define PI (3.14)

int main(void){
    double r = 0;
    printf("请输入一个半径:");
    scanf("%lf",&r);
    printf("圆的面积是%.2lf\n",PI * r * r); 
    printf("圆的周长是%.2lf\n",PI * r * 2); 
    return 0;
}
