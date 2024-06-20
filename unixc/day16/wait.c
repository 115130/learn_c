#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }

    if(pid == 0){
        printf("%d进程,我是子进程,暂时不结束\n",getpid());
        sleep(5);
        //abort();
        int* p = NULL;
        *p = 1;
        return 0235;
    }
    int s;
    pid_t child_pid = wait(&s);
    if(child_pid == -1){
        perror("wait");
        return -1;
    }
    if(WIFEXITED(s)){
        printf("子进程正常终止,%d\n",WEXITSTATUS(s));
    }else{
        printf("子进程异常终止%d\n",WTERMSIG(s));
    }
    printf("%d进程:回收%d进程的僵尸\n",getpid(),child_pid);
    return 0;
}
