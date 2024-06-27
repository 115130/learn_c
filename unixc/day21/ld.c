#include<stdio.h>
#include<sys/syscall.h>
#include<pthread.h>
#include<unistd.h>

void* pthread_fun(void* a){
    printf("子线程:进程的PID:%d\n",getpid());
    printf("子线程:POSIX TID:%lu\n",pthread_self());
    printf("子线程:内核  TID:%ld\n",syscall(SYS_gettid));
    return NULL;
}

int main(void){
    pthread_t tid;
    pthread_create(&tid,NULL,pthread_fun,NULL);

    printf("主线程:进程的PID:%d\n",getpid());
    printf("主线程:POSIX TID:%lu\n",pthread_self());
    printf("主线程:内核  TID:%ld\n",syscall(SYS_gettid));
    pthread_join(tid,NULL);
    return 0;
}
