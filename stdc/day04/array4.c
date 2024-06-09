#include<stdio.h>
int main(void){
    int arr[4][3]={{1,2,3},{2,3,4},{3,4,5},{4,5,6}};
    printf("%lu\n",sizeof(arr));
    printf("%lu\n",sizeof(arr[0]));
    printf("%lu\n",sizeof(arr[0][0]));
    return 0;
}
