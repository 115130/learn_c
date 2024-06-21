#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void sigfun(int signum){
    printf("%d进程,信号处理开始\n",signum);
    fflush(stdout);
}

int main(void){
    if(signal(SIGALRM,sigfun) == SIG_ERR){
        perror("sigfun");
        return -1;
    }

    printf("alarm(10)返回%d\n",alarm(10));
    getchar();
    printf("alarm(5)返回%d\n",alarm(5));
    for(;;);
    return 0;
}
