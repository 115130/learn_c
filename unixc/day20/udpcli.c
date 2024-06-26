#include<stdio.h>
#include<sys/socket.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<string.h>

int main(void){

    printf("客户端:创建套接字\n");
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);

    if(sockfd == -1){
        perror("socket");
        return -1;
    }
    
    printf("客户端:组织地址结构\n");
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(7898);//字节序准换
    ser.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    
    printf("客户端:业务处理\n");
    while(1){
        char buf[64] = {};
        struct sockaddr_in client_ser;
        unsigned int len = sizeof(ser);
        fgets(buf,64,stdin);
        if(strcmp(buf,"!\n")==0){
            break;
        }
        if(sendto(sockfd,&buf,strlen(buf),0,(struct sockaddr *)&ser,len) == -1){
            perror("sendto");
            return -1;
        }

        if(recvfrom(sockfd,&buf,sizeof(buf),0,(struct sockaddr *)&client_ser,&len)==-1){
            perror("recvfrom");
            return -1;
        };

        printf("服务器将buf变成了%s",buf);
        for(int i = 0;i<strlen(buf);i++){
          buf[i] = toupper(buf[i]); 
        }
    }
    


    return 0;
}
