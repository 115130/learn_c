#include<stdio.h>
int main(void){
    int num1 = 8;
    int num2 = 9;
    int temp = 0;
    printf("num1 = %d, num2 = %d\n", num1, num2);

    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("num1 = %d, num2 = %d\n", num1, num2);

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
