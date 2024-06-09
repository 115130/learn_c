#include<stdio.h>

typedef int (*pfun_t)(int,int);

int add(int a,int b){ 
    return a + b;
}

int sub (int a,int b){
    return a - b;
}

int calc(int a,int b,pfun_t p){ 
    printf("%d\n",p(a,b));
    return p(a,b);
}

int main(void){
    calc(3,2,add);
    calc(3,2,sub);
    return 0;
}
