#include<stdio.h>
#include<stdlib.h>
const int const_global = 10;
int init_global = 20;
int uninit_global;

int main(int argc,char** argv,char** envp){
    const static int const_static = 30;    
    static int int_init = 40;
    static int uninit_static;
    const int const_local = 50;
    int local;
    char* string = "hello";
    int* heap = malloc(sizeof(int));
    printf("  参数和环境区域\n");
    printf("  命令行参数%p  \n",argv);
    printf("  环境变量%p  \n",envp);
    printf("  栈区域  \n");
    printf("  常局部变量%p\n",&const_local);
    printf("  普通局部变量%p\n",&local);
    printf("  堆区   \n");
    printf("  堆区变量%p\n",heap);
    printf("  BSS\n");
    printf("  未初始化静态变量%p\n",&uninit_global);
    printf("  数据区\n");
    printf("  未初始化静态变量%p\n",&uninit_static);
    printf("  初始化静态变量%p\n",&init_global);
    printf("  初始化静态变量%p\n",&init_global);
    printf("  代码区\n");
    printf("  常全局变量%p\n",&const_global);
    printf("  常静态变量%p\n",&const_static);
    printf("  字符串常量%p\n",string);
    printf("  函数%p\n",main);
    return 0;
}
