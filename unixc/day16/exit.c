#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void exitfun(void){
    printf("我是退出处理函数\n");
}
void exitfun2(int status,void* abc){

    printf("我是退出处理函数%s,退出码是%d\n",(char*)abc,status);
}

int fun(void){
    printf("我是fun函数\n");
    //exit(139);

    return 10;
}

int main(void){
    _exit(1);
    atexit(exitfun);
    on_exit(exitfun2,"hello");
    printf("fun函数返回%d\n",fun());
    return 139;
}
