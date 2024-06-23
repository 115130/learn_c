//将内存文件映射到磁盘文件
#include<stdio.h>
#include<sys/mman.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    int fd = open("./mmap.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    ftruncate(fd,4096);
    char* c = mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    strcpy(c,"sajdhuvhuiysgs");
    close(fd);
    return 0;
}
