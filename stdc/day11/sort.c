#include<stdio.h>
#include"sort.h"

void bubble(int * arr,int size){
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            if(arr[i]>arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void select(int * arr,int size){

}
void insert(int * arr,int size){

}
void quick(int * arr,int size){

}
void list(int* arr,int size){
     for(int i = 0;i < size;i++){
        printf("%d ",arr[i]);   
     }
    printf("\n");
}
