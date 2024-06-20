#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    //创建子进程
    pid_t pid = fork();

    if(pid == -1){
        perror("fork");
        return -1;
    }

    //子进程代码,暂时不结束
    if(pid == 0){
        printf("%d进程,我是子进程\n",getpid());
        sleep(10);
        return 0;
    }
    //父进程代码,非阻塞方式回收,循环回收
    for(;;){
        pid_t chilid_pid = waitpid(pid,NULL,WNOHANG);
        if(chilid_pid == -1){
            perror("waitpid");;
            return -1;
        }else if(chilid_pid == 0){
            printf("%d进程:子进程在运行,无法回收,我先睡觉\n",getpid());
            sleep(10);
        }else{
            printf("%d进程已被回收\n",chilid_pid);
            break;
        }
    }
    //
    return 0;
}
