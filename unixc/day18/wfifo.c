#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void){
    //创建有名管道文件
    printf("创建有名管道文件\n");
    if(mkfifo("./myfifo",0664) == -1){
        perror("mkfifo");
        return -1;
    }
    //打开有名管道文件
    printf("打开有名管道文件\n");
    int fd = open("./myfifo",O_WRONLY);
    if(fd==-1){
        perror("open");
        return -1;
    }
    //写入数据
    printf("发送数据\n");
    while(1){
        //通过键盘输入数据,scanf fscanf read getchar
        char buf[64]={};
        printf("输入数据\n");
        fgets(buf,sizeof(buf),stdin);
        //认为指定退出条件
        if(strcmp(buf,"!\n") == 0){
            
            break;
        }
        printf("发送数据\n");
        if(write(fd,buf,sizeof(buf)) == -1){
            perror("write");
        };
    }
    //关闭有名管道文件

    printf("%d进程:关闭管道",getpid());
    close(fd);

    //删除有名管道文件
    printf("%d进程:删除管道文件",getpid());
    if(unlink("./myfifo") == -1){
        perror("unlink");
        return -1;
    }
    perror("%d进程,大功告成!\n");
    return 0;
}
