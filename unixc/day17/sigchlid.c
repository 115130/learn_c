#include <errno.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>

void sigchild(int signum){
    printf("%d进程捕获到%d的信号",getpid(),signum);
    fflush(stdout);
    for(;;){
        pid_t pid = waitpid(-1,NULL,WNOHANG);
        sleep(2);
        if(pid == 0){
            printf("子进程正在运行,等会再收\n");
        }else if(pid == -1){
            printf("进程%d异常终止\n",getpid());
           if(errno == ECHILD){
                printf("没有子进程了\n");
                break;
            }else{
                perror("wait");
                exit(-1);
            }
        } else{
            printf("进程%d正常终止\n",getpid());
            fflush(stdout);
        }
        printf("进程%d回收了进程pid为%d的进程\n",getpid(),pid);
        fflush(stdout);
    }
}

int main(void){
    if ( signal(SIGCHLD,sigchild)  == SIG_ERR) {
        perror("signal");
        return -1;
    };
    for(int i = 0; i <5;i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return -1;
        }
        if(pid == 0){
            printf("%d进程:我是子进程\n",getpid());
            fflush(stdout);
            sleep((i*2));
            printf("%d进程:我是子进程,我要似了\n",getpid());
            fflush(stdout);
            return 0;
        }
    }
    pid_t oldsix = fork();
    if(oldsix==-1){
        perror("fork");
        return -1;
    }
    if(oldsix == 0){
        printf("%d进程,我是老刘",getpid());
        sleep(6);
        return 0;
    }
    for(;;);

    return 0;
}
