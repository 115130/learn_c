#include<stdio.h>
#include <string.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    int fd = open("./shared.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);
    if(fd ==-1){
        perror("open");
        return -1;
    }

    char arr[100]= "dashiyudasgouidashaso\n8d加快速度化解对方赛欧ijhkvgciucdxshjlikvhcou8ihqwol;ehkuqwghro";
    ssize_t size = write(fd,arr,strlen(arr));
    if(size == -1){
        perror("write");
        return -1;
    }
    printf("实际写入文件%ld个字节\n",size);
}
