#include<stdio.h>
#include<unistd.h>

int main(void){
    while(1){
        printf("当前堆尾%p \n",sbrk(0));
        int* p1 = sbrk(0);
        brk(p1+1);
        printf("当前堆尾%p \n",p1);
        *p1 = 100;
        double* p2 = sbrk(0);
        brk(p2+1);
        printf("当前堆尾%p %p\n",p1,p2);
        brk(p1);
        printf("当前堆尾%p \n",sbrk(0));
    }
    return 0;
}
