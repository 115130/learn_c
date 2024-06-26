#include<stdio.h>
#include<sys/socket.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<string.h>

int main(void){

    printf("服务器:创建套接字\n");
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1){
        perror("socket");
        return -1;
    }
    
    printf("服务器:组织地址结构\n");
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(7898);//字节序准换
    ser.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    printf("服务器:绑定套接字和地址结构\n");
    if(bind(sockfd,(struct sockaddr*)&ser,sizeof(ser))==-1){
        perror("bind");
        return -1;
    }
    printf("服务器:业务处理\n");
    while(1){
        struct sockaddr_in client_ser;
        char buf[64] = {};
        unsigned int len = sizeof(client_ser);
        recvfrom(sockfd,&buf,sizeof(buf),0,(struct sockaddr *)&client_ser,&len);
        printf("服务器接受到%s:%hu的客户端的连接\n",inet_ntoa((struct in_addr)client_ser.sin_addr),ntohs(client_ser.sin_port));
        for(int i = 0;i<strlen(buf);i++){
          buf[i] = toupper(buf[i]); 
        }
        sendto(sockfd,&buf,strlen(buf)-1,0,(struct sockaddr *)&client_ser,sizeof(client_ser.sin_addr.s_addr));
    }


    return 0;
}
