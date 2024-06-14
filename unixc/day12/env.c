#include<stdio.h>
int main(void){
    extern char** environ;
    char** pp;
    for(pp = environ;*pp;++pp){
        
        printf("%s\n",*pp);
    }
    *pp = "dsafg=123";
    return 0;
}
