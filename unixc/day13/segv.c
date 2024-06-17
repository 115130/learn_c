
#include<stdio.h>
#include<stdlib.h>
int main(){
    const static int ptr = 0x12345678;
    int* t = (int *)&ptr;
    *t = 1;
    printf("%d\n",*t);
}
