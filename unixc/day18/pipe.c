#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){

    int fd[2] = {};   
    if(pipe(fd) == -1){
        perror("pipe");
        return -1;
    }

    printf("fd[0] = %d\n",fd[0]);
    printf("fd[1] = %d\n",fd[1]);
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }

    if(pid == 0){
         printf("%d进程,关闭读端口\n",getpid());
        close(fd[0]);
        printf("%d进程:发送数据\n",getpid());

        while(1){
            char buf[64] = {};
            ssize_t size = read(fd[1],buf,strlen(buf-1));
            if(size == -1){
                perror("read");
                return -1;
            }
            if(size == 0){
                printf("结束\n");
                break;
            }
            printf("%s\n",buf);
        }
        close(fd[1]);
        return 0; 
    }
    printf("%d进程,关闭读端口\n",getpid());
    close(fd[0]);
    printf("%d进程:接收数据\n",getpid());
    while(1){
        char buf[64] = {};
        fgets(buf,sizeof(buf),stdin);
        if(strcmp(buf,"!\n")){
            break;
        }
        if(write(fd[1],buf,strlen(buf)) == -1){
            perror("write");
            return -1;
        }
    }
    close(fd[1]);
    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }

    return 0;
}
