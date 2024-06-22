//brk分配内存
#include<stdio.h>
#include<unistd.h>
int main(void){
    int* p = sbrk(0);
    int  o = brk(p + 1);//需要给已有的地址
    printf("%d",o);
    *p = 12;
    printf("%d",*p);
    return 0;
}
