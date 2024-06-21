#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigfun(int signum){
    printf("%d进程,%d信号处理开始\n",getpid(),signum);
    sleep(3);
    printf("%d进程,%d信号处理开始\n",getpid(),signum);
}

int main(void){
    if(signal(SIGINT,sigfun) == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("%d进程,我要一睡不起\n",getpid());
    int res = pause();
    printf("%d进程:pause函数返回%d\n",getpid(),res);
    
    return 0;
}
