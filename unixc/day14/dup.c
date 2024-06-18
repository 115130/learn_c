#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(void){
    //打开文件得倒文件描述符
    int oldfd = open("dup.txt",O_RDWR|O_CREAT|O_TRUNC,0664);
    if(oldfd == -1){
        perror("open");
        return -1;
    }
    printf("oldfd = %d\n",oldfd);
        
    //复制文件描述符oldfd.得到新的文件描述符newfd
    int newfd = dup(oldfd);
    if(newfd == -1){
        perror("dup");
        return -1;
    }
    printf("newfd = %d\n",newfd);
    //通过oldfd写入数据hello world
    if(write(oldfd,"hello world",strlen("hello world")) == -1){
        perror("write");
        return -1;
    }

    //通过newfd修改文件内读写位置
    if(lseek(newfd,8,SEEK_CUR) == -1){
        perror("lseek");
        return -1;
    }

    //通过oldfd再次写入文件 linux!
    if(write(oldfd,"linux",strlen("linux")) == -1){
        perror("write");
        return -1;
    }

    close(oldfd);
    close(newfd);
    return 0;
}
