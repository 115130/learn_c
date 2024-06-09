#include<stdio.h>
void swap(char** p1,char** p2){
    char* p3 = *p1;
    *p1 = *p2;
    *p2 = p3;
}
int main(void){
    char* p1 = "hello";
    char* p2 = "world";
    printf("%s,%s\n",p1,p2);
    swap(&p1,&p2);

    printf("%s,%s",p1,p2);

    return 0;
}
