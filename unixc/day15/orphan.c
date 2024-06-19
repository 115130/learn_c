#include<stdio.h>
#include<unistd.h>
int main(void){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }

    if(pid == 0){
        printf("父进程是%d",getppid());
        sleep(2);
        printf("父进程是%d",getppid());
        return 0;
    }
    sleep(1);

    return 0;
}
