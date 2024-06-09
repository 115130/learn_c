#include<stdio.h>

typedef union Data{
    int i;
    float f;
    char str[20];
} data;

int main(void){
    data d;
    d.i = 10;
    printf("%d\n", d.i);

    d.f = 3.14;

    printf("%d\n",d.i);
    printf("%lf\n",d.f);
    d.i = 10;
    printf("%d\n",d.i);
    printf("%lf\n",d.f);
    printf("%lf\n",d.f);
    printf("%lf\n",d.f);
    printf("%lf\n",d.f);

    return 0;
}
