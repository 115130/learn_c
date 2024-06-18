#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main(void){
    int fd = open("./test.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
    if(fd == -1){
        perror("open");
        return -1;
    }

    char* he = "hello world!";
    char* li = "linux!";
    ssize_t size = write(fd,he,strlen(he));
   

    if(size==-1){
        perror("write");
        return -1;
    }
    if(lseek(fd,-6,SEEK_CUR)==-1){
        perror("lseek");
        return -1;
    }
    if(write(fd,li,strlen(li))==-1){
        perror("write");
        return-1;
    }
    if(lseek(fd,8,SEEK_END)==-1){
        perror("lseek");
        return -1;
    }
     if(write(fd,"地三鲜",strlen("地三鲜"))==-1){
        perror("write");
        return-1;
    }  
    if(lseek(fd,-8,SEEK_SET)==-1){
        perror("lseek");
        return -1;
    }
     if(write(fd,"地三鲜",strlen("地三鲜"))==-1){
        perror("write");
        return-1;
    }
     
    close(fd);
    return 0;
}
