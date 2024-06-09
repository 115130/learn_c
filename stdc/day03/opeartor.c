#include<stdio.h>
int main (void){
    int i =10;
    int y = i++ + ++i + i++;
    printf("%d %d",i,y);
}
