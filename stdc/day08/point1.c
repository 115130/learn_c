#include<stdio.h>
int main(void){
    char * arr[]= {"咖啡","浓茶"};

    char ** p = arr;
    printf("%s %s\n",*p,*(p+1));
    printf("%s %s\n",p[0],p[1]);
    return 0;
}
