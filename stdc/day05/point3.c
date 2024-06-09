#include<stdio.h>
int main(void){
    int a = 0x12345678;
    short *a1 =(short*) &a;
    printf("%hx",*a1);
    return 0;
}
