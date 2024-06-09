#include <stdio.h>
int main(void){
    unsigned char year = 0;
    printf("请输入年龄");
    scanf("%hhu",&year);
    if(year < 18 || year >60){
        printf("门票%.2f",10 * 0.8);
    }else{
        printf("门票%.2f",10.0);
    }
    return 0;
}
