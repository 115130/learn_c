#include<stdio.h>
int recursion(int i,int count){
    i = i / 2 - 1;
    count++;
    printf("还有%d个桃子\n",i);
    if (i == 1){
        return count;
    }
    return recursion(i,count);
    
}
int main(void){
    int i = 2000;
    int count = recursion(i,0);
    printf("总数是%d",count);
    return 0;
}
