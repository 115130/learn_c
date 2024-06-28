#include "singals.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int init_signals(){
    printf("%d.%ld > 忽略大部分信号\n",getpid(),syscall(SYS_gettid));
    for(int i = SIGHUP;i<SIGRTMAX;i++){
        if(i != SIGINT && i!= SIGTERM){
            signal(i,SIG_IGN);
        }
    }
    return 0;
}

