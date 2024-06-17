#include<stdio.h>
#include<unistd.h>

int main(void){
    printf("当前堆尾%p \n",sbrk(0));
    int* p1 =sbrk(4);
    printf("当前堆尾%p \n",p1);
    *p1 = 100;
    double* p2 = sbrk(8);
    printf("当前堆尾%p %p\n",p1,p2);
    sbrk(-(8+4));
    printf("当前堆尾%p \n",sbrk(0));

    return 0;
}
