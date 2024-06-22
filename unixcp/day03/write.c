#include<stdio.h>
#include <string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    int fd = open("./write.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
    write(fd,"hello",strlen("hello"));    
    char t[50];
    lseek(fd,0,SEEK_SET);
    read(fd,t,5);
    printf("%s\n",t);
    close(fd);
    return 0;
}
