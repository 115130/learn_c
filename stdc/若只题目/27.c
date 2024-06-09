#include<stdio.h>
int main(void){
    char c[] = "abc";
    int i = 0;
    do;while(c[i++]!='\0');printf("%d",i-1);
    return 0;
}
