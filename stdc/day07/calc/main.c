#include<stdio.h>
#include "calc.h"

int main(void){
    int a =123 ,b=456;
    printf("a + b = %d\n",add(a,b));
    printf("a - b = %d\n",sub(a,b));
    return 0;
}
