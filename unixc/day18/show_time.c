#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>
#include<unistd.h>

void show_time(int signum){
    time_t now = time(NULL);

    struct tm* l = localtime(&now);

    printf("\r%02d:%02d:%02d",l->tm_hour,l->tm_min,l->tm_sec);
    alarm(1);
}

int main(void){
    setbuf(stdout,NULL);
    if(signal(SIGALRM,show_time) == SIG_ERR){
        perror("signal");
        return -1;
    }
    fprintf(stderr,"\n");
    alarm(1);
    while(1);
    return 0;
}
