//基于tcp协议的服务器
#include <netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#include<signal.h>
#include<errno.h>
#include<stdlib.h>

void handle(int sig_handle){
    while(1){
        pid_t pid = waitpid(-1,NULL,WNOHANG);
        if(pid == -1){
            if(errno!=ECHILD){
                printf("没有子进程了\n");
                break;
            }else{
                perror("wait");
                exit(1);;
            }
            if(!pid){
                break;
            }
        }
    }
}

int main(void){
    if(signal(SIGCHLD,handle) == SIG_ERR){
        perror("signal");
        return -1;
    }
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
    ser.sin_addr.s_addr = inet_addr("0.0.0.0"); 
    printf("服务器:绑定套接字和地址结构\n");
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
    struct sockaddr_in client_ser;
    unsigned int len = sizeof(client_ser);
    while(1){
        int accept_fd = accept(sockfd,(struct sockaddr*)&client_ser,&len);
        pid_t pid = fork();
        if(pid == 0){
            // 后续传输由accept_fd做
                    
            if(accept_fd == -1){
                perror("accept");;
                return -1;
            }
            printf("服务器接受到%s:%hu的客户端的连接\n",inet_ntoa((struct in_addr)client_ser.sin_addr),ntohs(client_ser.sin_port));
            printf("服务器:业务处理\n");
            while(1){
                char buf[64] = {};
                ssize_t size = read(accept_fd,buf,sizeof (buf)-1);
                if(size == -1){
                    perror("read");
                    return -1;
                }
                if(size == 0){
                    printf("对方关闭套接字");
                    break;
                }
                printf("%s",buf);
                for (int i = 0;i < strlen(buf);i++){
                    buf[i] = toupper(buf[i]);
                }
                if(write(accept_fd,buf,strlen(buf)) == -1){
                    printf("write");
                    return -1;
                }
            }
            printf("服务器:关闭套接字");
            close(accept_fd);
            close(sockfd);
            return 0;
        }
        close(accept_fd);
    }
}

