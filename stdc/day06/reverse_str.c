#include<stdio.h>
#include <string.h>
int main(void){
    char arr[100] = {};
    scanf("%s",arr);
    int size = strlen(arr);
    for(int i = size;i >= 0;i--){
        printf("%c",arr[i]);
    }
}
