#include<stdio.h>
int main(void){
    int sum = 0;
    for(int i = 1;i<=100;i++){
        sum+=i;
    }
    printf("1到100的总和是%d",sum);
    return 0;
}
