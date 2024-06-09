#include<stdio.h>
int main(void){
    int a = 10; //普通的整形变量
    int * p = &a; //一级指针,存普通整型变量地址
    int ** pp = &p; // 二级指针,存一级指针变量地址
    printf("a = %d ,&a = %p\n",a,&a);
    printf("p = %p,&p = %p\n",p,&p);
    printf("pp = %p,&pp = %p\n",pp,&pp);
    printf("*pp %p , **pp %d\n",*pp,**pp);
    printf("*pp %p , **pp %d\n",*pp,**pp);
    printf("*pp %p , **pp %d\n",*pp,**pp);
    
    *p = 11;
    printf("a=%d\n",a);
    
    **pp = 12;
    printf("a=%d\n",a);

    *p = 11;
    printf("a=%d\n",a);

    return 0;
}
