#include<stdio.h>
int main(void){
    for(int i = 0;i < 5;i++){
        if(i == 2){
            break;
        }
        printf("i = %d",i);
    }
    return 0;
}
