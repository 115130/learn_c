//使用sbrk的方式分配内存
#include<stdio.h>
#include<unistd.h>

int main(void){
    int* i = sbrk(5);
    printf("i的大小是%lu",sizeof(*i));
    *i = 100;
    *(i+1) = 500;
    printf("i的大小是%d",*(++i));
}
