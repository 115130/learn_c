#include<stdio.h>
int add(int i,int b){
    return i + b;
}

int ppadd(int (*padd)(int,int) ){
    return padd(3,2);
}

int main(void){
    int (*padd)(int,int) = add;
    printf("%d",ppadd(padd)); 
}
