//展示环境变量
#include<stdio.h>
int  main(void){
    extern char** environ;//extern链接了外部的环境变量
    char** pp;
    for(pp = environ;*pp;pp++){
        printf("%s\n",*pp);
    }

    return 0;
}
