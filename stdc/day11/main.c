#include <stdio.h>
#include "sort.h"
int main(void){
    int arr[]={30,20,10,50,60,70,90,40};
    int size = sizeof(arr)/sizeof(arr[0]);
    list(arr,size);
    bubble(arr,size);
    list(arr,size);
    return 0;
}
