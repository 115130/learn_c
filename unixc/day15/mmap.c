#include<stdio.h>
#include<sys/mman.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    int fd = open("./mmap.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    if(ftruncate(fd,4096)==-1){
        perror("ftrynce");
        return -1;
    }

    char* c = mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(c == MAP_FAILED){
       perror("mmap") ;
       return -1;
    }
    strcpy(c,"41654dsadhgf");
    printf("%s",c);
    if(munmap(c,4096)==-1){
        perror("munmap");
        return -1;
    };
    close(fd);
    return 0;
}
