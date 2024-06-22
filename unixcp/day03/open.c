#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    int fd = open("./open.t",O_RDWR|O_CREAT|O_TRUNC,0666);
    
    
    close(fd);
    return 0;
}
