//基于tcp协议的客户端
#include <netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/wait.h>

int main(void){
    printf("客户端:创建套接字\n");
    int sockfd  = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1){
        perror("socket");
        return -1;
    }
    printf("客户端:组织服务器地址结构\n");
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(7898);//字节序准换
    ser.sin_addr.s_addr = inet_addr("127.0.0.1"); 
  
    printf("客户端:发送连接\n");
    struct sockaddr_in server;
    unsigned int len = sizeof(server);

    // 后续传输由accept_fd做
    if(connect(sockfd,(struct sockaddr*)&ser,sizeof(ser)) ==-1){
        perror("connect");
        return -1;
    }
    printf("客户端:业务处理\n");
    while(1){
        char buf[64] = {};
        printf("输入要传输的字符串");
        fgets(buf,sizeof(buf),stdin);

        if(strcmp(buf,"!\n") == 0){
            break;
        }


        if(send(sockfd,buf,strlen(buf),0) == -1){
            printf("send");
            return -1;
        }

        ssize_t size = recv(sockfd,buf,sizeof (buf)-1,0);

        if(size == -1){
            perror("recv");
            return -1;
        }
        printf("%s",buf);
    }
    printf("客户端:关闭套接字");
    close(sockfd);
    return 0;
}

