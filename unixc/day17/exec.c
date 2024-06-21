//为验证子进程是否继承父进程的信号处理方式
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void sigfun(int signum){
    printf("%d进程:捕获到%d信号\n",getpid(),signum);
}

int main(void){
    if(signal(SIGINT,SIG_IGN) == SIG_ERR){
        perror("signal");
        return 0;
    }
    if(signal(SIGQUIT,sigfun) == SIG_ERR){
        perror("signal");
        return 0;
    }

    pid_t p  = fork();
    if(p == -1){
        perror("fork");
        return -1;
    }
    if(p == 0){
        if(execl("./test",NULL) == -1){
            perror("exec");
            return -1;
        };
    }
    return 0;
}
