#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
    int fd = open("./ftab.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    char* t = "hello world";
    if(write(fd,t,strlen(t)) == -1){
        perror("write");
        return -1;
    }
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }

    if(pid == 0){
        lseek(fd,-5,SEEK_CUR);
        close(fd);
        return 0;
    }else{
        sleep(1);
        char* li = "linux"; 
        if(write(fd,li,strlen(li))==-1){
            perror("write");
            return -1;
        }
        close(fd);
        return 0;
    }

}
