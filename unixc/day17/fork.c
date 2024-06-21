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


    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }

    if(pid == 0){
        printf("%d进程:我是子进程\n",getpid());
        for(;;);
        return 0;
    }

    printf("%d我是父进程\n",getpid());
    sleep(1);
    

    return 0;
}
