#include<stdio.h>
int main(void){
    int a = 10;
    int *p = &a;
    printf("%d ",*p);
    printf("%d ",a);
    *p = 20;
    printf("%d ",a);
    printf("%p ",p);
    int **p1 = &p;
    printf("**p1:%p,*p:%d",p1,**p1);
    return 0;
}
