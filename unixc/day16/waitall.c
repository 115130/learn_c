#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>

int main(void){
    pid_t pid; 
    for(int i = 0;i < 20;i++){
        pid = fork();
        if(pid == -1){
            perror("fork");
            return -1;
        }
        if(pid == 0){
            printf("%d进程:我是子进程\n",getpid());
            sleep(1 + i);
            //return 0;
        }
    }
    if(pid == 0){
        return 0;
    }
    
    for(;;){
        pid = wait(NULL);
        if(pid == -1){
            if(errno == ECHILD){
                printf("没有子进程\n");
                break;
            }else{
                perror("wait");
                return -1;
        }
    }
    }
}
