#include<unistd.h>
#include<stdio.h>

int main(void){
    pid_t p;
    printf("%d进程:我是父进程\n",getpid());
        p = fork();
    if(p == -1){
        perror("fork");
        return -1;
    }
    if(p==0){
        printf("%d进程,我是子进程\n",getpid());
        return 0;
    }else{
        printf("%d进程,我是父进程\n",getpid());
        return 0;
    }

    printf("996\n");
    return 0;
}
