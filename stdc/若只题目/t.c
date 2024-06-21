#include<stdio.h>
void f(char* s,char* t){
    while(*t){
        *s++=*t++;
    }
    *s = '\0';
}

int main(void){
    char test[20] = "dsadd";
    char test1[20] = "123456";
    f(test,test1);
    printf("%s",test);
    int a =-2;
    printf("%d",!a);
}
