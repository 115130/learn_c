#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    int fd = open("./shared.txt",O_RDONLY);
    if(fd == -1){
        perror("open");
        return -1;
    }
    char* buf = malloc(100);
    ssize_t size = read(fd,buf,100);
    if(size == -1){
        perror("read");
        return -1;
    }
    printf("%s",buf);
    close(fd);
    return 0;
}

