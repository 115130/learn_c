#include<stdio.h>
int main(void){
    int i = 1;
    int sum = 1;
    while(i!=100){
        i++;
        sum +=i;
    }
    printf("%d %d",i,sum); 

    return 0;
}
