#include <stdio.h>
#include "sort.h"
int main(void){
    int arr[]={60,60,30};
    int size = sizeof(arr)/sizeof(arr[0]);
    //list(arr,size);
    //bubble(arr,size);
    //insert(arr,size);
    //select(arr,size);
    quick(arr,0,size-1);
    //printf("%d",sequ_search(arr,size,50));
    //printf("%d",half_search(arr,size,50));
    //list(arr,size);
    return 0;
}
