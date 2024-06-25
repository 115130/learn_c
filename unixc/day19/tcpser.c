//基于tcp协议的服务器
#include <netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<arpa/inet.h>
#include<signal.h>
#include<sys/wait.h>

int main(void){
    printf("服务器:创建套接字\n");
    int sockfd  = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1){
        perror("socket");
        return -1;
    }
    printf("服务器:组织地址结构\n");
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(7898);//字节序准换
    ser.sin_addr.s_addr = inet_addr("192.168.99.127"); 
    printf("服务器:绑定套接字和地质结构\n");
    if(bind(sockfd,(struct sockaddr*)&ser,sizeof(ser))==-1){
        perror("bind");
        return -1;
    }

    printf("服务器:启动监听\n");
    if(listen(sockfd,4096) == -1){
        perror("listen");
        return -1;
    };

    printf("服务器:等待链接\n");
    unsigned int acc;
    int accept_fd = accept(sockfd,(struct sockaddr*)&ser,&acc);
    if(accept_fd == -1){
        perror("accept");;
        return -1;
    }
    printf("服务器:接受链接\n");
    //recv()

    return 0;
}

