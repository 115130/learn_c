#include<stdio.h>

int add(int a,int b);

int main(void){
    printf("%d",add(4,7));
    return 0;
}

int add(int a,int b){
    return a + b;
}
