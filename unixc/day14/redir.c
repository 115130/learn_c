#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
    close(STDOUT_FILENO);
    int fd = open("out.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
    printf("fd = %d\n",fd);
    return 0;
}
