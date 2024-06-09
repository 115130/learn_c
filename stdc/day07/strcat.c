#include<stdio.h>
int main(void){
    char s[100]="123";
    char * s1="123";
    int t =0,t1=0;
    while(*(s+t)!=0){
        t++;
    }
    while(*(s1+t1)!=0){
        s[t+t1] = s1[t1];
        t1++;
    }
    printf("%s",s);
    return 0;
}
