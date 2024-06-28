#include <stdio.h>
#include "socket.h"
#include "unistd.h"
#include <sys/socket.h>
#include "fcntl.h"
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <arpa/inet.h>

static int sockfd = -1;

int init_socket(short port){
  sockfd = socket(AF_INET, SOCK_STREAM,0);

  if(sockfd == -1){
    perror("socket");
    return -1;
  }
  
  int on  = 1;
  //手动释放port占用
  printf("%d.%ld设置套接字",getpid(),syscall(SYS_gettid));
  if(setsockopt(sockfd,SOL_SOCKET ,SO_REUSEPORT , &on,sizeof(on) ) ==-1){
    perror("");     
    return -1;
  }
  printf("%d.%ld组织地址结构",getpid(),syscall(SYS_gettid));
  struct sockaddr_in ser;
  ser.sin_port = htons(port);
  ser.sin_family = AF_INET;
  ser.sin_addr.s_addr = INADDR_ANY;

  printf("%d.%ld开始绑定地址",getpid(),syscall(SYS_gettid));
  if(bind(sockfd, (struct sockaddr*)&ser,sizeof(ser)) == -1){
    perror("bind");
    close(sockfd);
    return -1;
  }
  
  printf("%d.%ld开始监听",getpid(),syscall(SYS_gettid));
  if(listen(sockfd, 1024) == -1){
    perror("listen");
    return -1;
  }
  return 0;
}

int accept_client(void){
  
  printf("%d.%ld等待客户端连接",getpid(),syscall(SYS_gettid));
  struct sockaddr_in cli ; 
  socklen_t len;
  int conn = accept(sockfd,(struct sockaddr*)&cli,&len);
  if(conn ==-1){
    perror("accept");
    return -1;
  }
  printf("%d.%ld>已接收到%s,%hu的客户端连接",getpid(),syscall(SYS_gettid),inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
  
  return conn;
}

char* recv_request(int conn){
  ssize_t len = 0;
  char* req = NULL;
  while(1){
    char buf[1024] = {};
    ssize_t size = recv(conn,buf,sizeof(buf)-1,0);
    if(size == -1){
      free(req);
      perror("recv");
      return NULL;
    }
    if(size == 0){
      printf("%d.%ld客户端关闭套接字",getpid(),syscall(SYS_gettid));
      free(req);
      return NULL;
    }
    req = realloc(req, len+size+1);
    memcpy(req+len, buf, size+1);

    len = len + size;
    if(strstr(req,"\r\n\r\n")){
      break;
    }
  }
  return req;
}
int send_head(int conn, const char* head){
    if(send(conn,head,strlen(head),0) == -1){
      perror("send_head");
      return -1;
    }
    return 0;
}

int send_body(int conn, const char* body){
    int fd = open(body,O_RDONLY);
    if(fd == -1){
      perror("fd");
      return -1;
    }
    char buf[1024];
    ssize_t len;
    while((len = read(fd,buf,sizeof(buf)-1))>0){
      if(send(conn,buf,len,0) == -1){
        perror("sned_body");
        close(fd);
        return -1;
      }
    }
    if(len == -1){
      perror("read");
      close(fd);
      return -1;
    }
    close(fd);
    return 0;
}

void deinit_socket(){
  close(sockfd);
}

