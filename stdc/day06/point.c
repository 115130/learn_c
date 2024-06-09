#include<stdio.h>
int main(void){
    printf("%lu\n",sizeof(1 ? 1 : 0.9));
    
    printf("%d\n",-7 + 3u > 0);
    printf("%d\n",-7 + 3u);
    int a = 300;
    char c = a;
    printf("%d",c);
    return 0;
}
