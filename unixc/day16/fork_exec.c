#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }

    if(pid == 0){
        if(execl("./new","dsaujghikujdasguigas",NULL)==-1){
            perror("execl");
            return -1;
        }
    }
    int status;
    if(waitpid(-1,&status,0) == -1){
        perror("wait");
        return -1;
    }else{
        if (WIFEXITED(status)){
           printf("正常终止"); 
        }else{
           printf("异常终止"); 
        }
        printf("成功回收%d进程",pid);
    } 
    pid_t pid2 = fork();

    if(pid2 == -1){
        perror("fork");
        return -1;
    }

    if(pid2 == 0){
        if(execlp("ls","-l",NULL)==-1){
            perror("execl");
            return -1;
        }
    }
    if(waitpid(-1,&status,0) == -1){
        perror("wait");
        return -1;
    }else{
        if (WIFEXITED(status)){
           printf("正常终止,%d\n",WEXITSTATUS(status)); 
        }else{
           printf("异常终止%d\n",WTERMSIG(status)); 
        }
        printf("成功回收%d进程",pid);
    }

    
}
