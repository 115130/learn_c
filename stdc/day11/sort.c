#include<stdio.h>
#include"sort.h"

void bubble(int * arr,int size){
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            if(arr[i]<arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void select(int * arr,int size){
    int j,i;
    int min;
    for(i = 0;i<size-1;i++){
        min = i;
        for(j = i+1;j < size;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}
void insert(int * arr,int size){
    int i,j;
    int key;
    for(i = 1;i < size;i++){
        key = arr[i];
        for(j = i-1;j >= 0;j--){
            if(arr[j]>key){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        } 
        arr[j+1] = key;
    }
    //if(arr[i]>arr[i-1]){

    //}
}


void quick(int *num, int start, int end) {
    int i = start;
    int j = end;
    int x = num[start];
    int tmp;

    while (i <= j) {
        while (num[i] < x) i++;
        while (num[j] > x) j--;

        if (i <= j) {
            tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
            i++;
            j--;
        }
    }

    if (start < j) quick(num, start, j);
    if (end > i) quick(num, i, end);
}


void list(int* arr,int size){
     for(int i = 0;i < size;i++){
        printf("%d ",arr[i]);   
     }
    printf("\n");
}
int sequ_search(int* num,int size,int data){
    for(int i = 0;i < size;i++){
        if(num[i] == data){
            return i;                  
        }
    }
    return -1;
}
int half_search(int* num,int size,int data){
    int left = 0;//左边界
    int right = size - 1;//右边界
    while(left<=right){
        int mid = (left + right) / 2;
        if(data < num[mid]){
            //向左找
            right = mid -1;
        }else if(data > num[mid]){
            left = mid + 1;
        }else{
            return mid;
        }
    }
}











