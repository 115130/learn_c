#include"../cal/math.h"

int main(void){
    int a = 123;
    int b = 456;
    show(a,'+',b,add(a,b));
    show(a,'-',b,sub(a,b));
    return 0;
}
