#include<stdio.h>
int main(void){
    int number = 0;
    printf("请输入一个三位的数字,本程序会判断是否是水仙花数");
    scanf("%d",&number);
    int temp = number;
    int unit = temp % 10;
    temp /= 10;
    int tens = temp % 10;
    temp /= 10;
    int hundred = temp % 10;
    if ((hundred * hundred * hundred + tens * tens * tens + unit * unit * unit) == number){
        printf("%d是水仙花数",number);
    } else {
        printf("%d不是水仙花数",number);
    }

    return 0;
}
