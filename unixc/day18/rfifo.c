#include <stdint.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd;
    printf("%d进程,打开管道文件\n",getpid());
    if((fd = open("./myfifo",O_RDONLY) == -1)){
       perror("open");
       return -1;
    }
    printf("%d进程,接收数据\n",getpid());
    while(1){
        char buf[64]={};
        ssize_t size = read(fd,buf,sizeof(buf)-1);
        if(size == -1){
            perror("read");
            return -1;
        }
        printf("输出数据为%s",buf);
        if(size == 0){
            printf("%d进程,对方关闭管道文件\n",getpid());
            break;
        } 
        printf("%s\n",buf);
    }
    printf("%d进程,关闭管道文件\n",getpid());
    close(fd);
    
    printf("%d进程,大功告成\n",getpid());
    return 0;
}
