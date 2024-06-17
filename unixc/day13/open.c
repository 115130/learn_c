#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(void){
    int fd = open("./open.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
    if(fd == -1){
        perror("open");
        return -1;
    }
    printf("fd = %d\n",fd);
    fd = close(fd);
    if(fd == -1){
        perror("close");
        return -1;
    }
    return 0;
}
