#include<stdio.h>
void swap(int *a,int *b);//函数声明
int main(void)
{
    int a= 2,b=10;
    printf("交换之前a:%d,b:%d\n",a,b);
    swap(&a,&b);
    printf("交换之后a:%d,b:%d",a,b);
    return 0;
}

void swap(int *a,int *b){//指针交换
    //将a和b存入a
    *a = *a ^ *b;
    //b^俩者之和会把b去掉,留下a
    *b = *b ^ *a;
    *a = *a ^ *b;
}
