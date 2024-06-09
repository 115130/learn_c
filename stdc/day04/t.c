#include<stdlib.h>
int main(void){
    unsigned long size = 4ul*1024ul*1024ul*1024ul;
    unsigned long *t = malloc(size);
    for (unsigned long i = 0;i<size;i++){
        t[i]=i;
        t++;
    }
    while(1){}
    return 0;
}
