#include<stdio.h>
#include<unistd.h>

int main(int argc,char** argv,char** envp){
    printf("进程的id%d",getpid());
    printf("命令行参数\n");
    for(char** pp = argv;*pp;pp++){
        printf("%s\n",*pp);
    }
    printf("环境变量\n");
    for(char** pp = envp;*pp;pp++){
        printf("%s\n",*pp);
    }
//    execl("./exec",NULL);

    return 0;
}
