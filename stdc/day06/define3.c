#include<stdio.h>

int main(void){
    int arr[SIZE] = {};
    printf("%lu",sizeof(arr)/sizeof(arr[0]));
    return 0;
}
