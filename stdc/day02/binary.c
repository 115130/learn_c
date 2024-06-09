#include<stdio.h>
int main(void){
    //int num = 65;
    //int num = 065;
    int num = 0x65;
    printf("八进制是%o,十进制是%d,16进制是%x\n",num,num,num);
    printf("八进制是%#o,十进制是%d,16进制是%#x",num,num,num);
    return 0;
}
