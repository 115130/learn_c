#include<stdio.h>
int main(void){
    t:
    for(int i = 1;i<=5 ;i++){
        printf("%i\n",i);
    }
    goto t;
    return 0;
}
