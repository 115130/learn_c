#include <stdint.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void updatedb(void){
    for(int i = 0;i < 5;i++){
        printf("正在更新第%d条数据.....\n",i+1);
        fflush(stdout);
        sleep(1);
    }
}
void sigfun(int signum){
    printf("%d进程:捕捉到%d信号\n",getpid(),signum);
}
int main(void){
    int signum = SIGINT;
    if(signal(SIGINT,sigfun)== SIG_ERR){
        perror("signal");

        return -1;
    }
    printf("%d进程屏蔽%d信号\n",getpid(),signum);
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset,signum);

    sigset_t oldset;
    sigprocmask(SIG_SETMASK,&sigset,&oldset);

    pid_t pid = fork();

    if(pid == 0){
        for(int i =0;i<5;i++){
            printf("%d进程向父进程发送信号%d\n",getpid(),signum);
            fflush(stdout);
            if(kill(getppid(),signum) == -1){
                perror("kill");
                return -1;
            }
            return 0;
        }
    }
    updatedb();
    printf("%d进程解除%d屏蔽\n",getpid(),signum);
    
    if(sigprocmask(SIG_SETMASK,&oldset,NULL) == -1){
        perror("sigprocmask");
        return -1;
    }

    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }

    return 0;
}
