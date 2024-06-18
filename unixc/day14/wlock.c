#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char** argv){
    int fd = open("./wlock.txt",O_WRONLY|O_CREAT|O_APPEND,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }

    struct flock lock;
    lock.l_type= F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;//一直锁到文件尾
    lock.l_pid = -1;
    while(fcntl(fd,F_SETLK,&lock) == -1){
        if(errno == EACCES || errno == EAGAIN){
             printf("文件被锁定,干点别的去\n");
             sleep(1);
        }else{
            perror("fcntl");
        }
    }

    for(int i = 0;i < strlen(argv[1]);i++){
        if(write(fd,&argv[1][i],sizeof(argv[1][i]))==-1){
            perror("write");
            return -1;
        }
        sleep(1);
    }
    struct flock unlock;
    unlock.l_type= F_UNLCK;
    unlock.l_whence = SEEK_SET;
    unlock.l_start = 0;
    unlock.l_len = 0;//一直锁到文件尾
    unlock.l_pid = -1;
    if(fcntl(fd,F_SETLK,&unlock) == -1){
        perror("fcntl");
        return -1;
    }
    return 0;
}
