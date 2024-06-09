#include <stdlib.h>
#include<stdio.h>
int main(void){
    int arr[] = {1,2,3,4,5,6};
    int *p = arr;
    char *str = malloc(4096 * 1);
    str[0] = '1';
    p++;
    printf("%d",*str);
    if(arr == &arr[0]){
        printf("arr的地址是%p,arr[0]的是%p,p的地址是%p,p的值是%d",arr,&arr[0],p,*p);
        printf("两个地址相等");
    }
    return 0;
}
