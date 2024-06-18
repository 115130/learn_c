#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    int fd = open("./trunc.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    char* c = "abcde";
    if(write(fd,c,strlen(c))==-1){
        perror("write");
        return -1;
    }
    close(fd);
    return 0;
}
