//信号处理
#include<signal.h>
#include<stdio.h>
#include<unistd.h>


void sigfun(int signum){
    printf("进程%d,得到%d号信号\n",getpid(),signum);
}

int main(void){
    //if(signal(SIGINT,SIG_IGN) == SIG_ERR){
    //    perror("signal");
    //    return -1;
    //}
    if(signal(SIGINT,sigfun) == SIG_ERR){
        perror("signal");
        return -1;
    }
        for(;;);
        
    return 0;
}
