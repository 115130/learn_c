#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
void sigfun(int signum){
    printf("%d进程:捕获到%d信号\n",getpid(),signum);
    fflush(stdout);
}

int main(void){
    pid_t pid = fork();    
    if(pid == -1){
        perror("fork");
        return -1;
    }
    if(pid == 0){
        if(signal(SIGINT,sigfun)==SIG_ERR){
            perror("signal");
            return -1;
        }
        for(;;);
        return 0;
    }
    getchar();
    if(kill(pid,SIGINT) == -1){
        perror("kill");
        return -1;
    }
    wait(NULL);
    if(kill(pid,0) == -1){
        if(errno == ESRCH){
            printf("进程不存在\n");
        }
    }else{
        printf("进程存在\n");
    }
    return 0;
}
