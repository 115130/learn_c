#include<stdio.h>
#include <string.h>

void fun(int *p,...){
    *p = 8;
}

int main(void){
    int x = 10;
    int *p = &x;
    printf("%d ",*p);
    for(int i = 0;i<20;i++){    
        int *p = &x;
        fun(p);
    }
    printf("%d\n",*p);
    printf("%lu\n",strlen("\t\"\065\xff\n"));
    return 0;
}
