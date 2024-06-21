#include<time.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void print_now_time(){
    time_t now;
    time(&now);
    struct tm* t = localtime(&now);
    printf("\r %04d-%02d-%02d %02d:%02d:%02d",
            t->tm_year + 1900,
            t->tm_mon + 1,
            t->tm_mday,
            t->tm_hour,
            t->tm_min,
            t->tm_sec);
    fflush(stdout);
    alarm(1);
}

int main(void){
    if(signal(SIGALRM,print_now_time) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //更快发送信号,alarm需要等1秒,ualarm可以指定微秒
    ualarm(1,0);

    while(1);

    return 0;
}
