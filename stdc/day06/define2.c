#include<stdio.h>
#define SUB(x,y) (x-y) 
#define SU(x) ((x) * (x))
#define MAX(x,y) (((x) > (y)) ? (x) : (y))

int main(void){
    printf("\n%d",SUB(4,1));
    printf("%lg\n",SUB(4.1,1));
    printf("%d\n",SU(2 + 3));
    printf("%d",MAX(2 , 3));
    return 0;
}
