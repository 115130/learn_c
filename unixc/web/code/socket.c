#include <stdio.h>
#include "socket.h"
#include "unistd.h"
#include <sys/socket.h>
#include "fcntl.h"
#include "sys/stat.h"
#include "sys/types.h"
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

static int sockfd = -1;

int init_socket(short port){
  sockfd = socket(AF_INET, SOCK_STREAM,0);
  
  struct sockaddr_in ser;
  ser.sin_port = port;
  ser.sin_family = AF_INET;
  ser.sin_addr.s_addr = INADDR_ANY;

  bind(sockfd, (struct sockaddr*)&ser,sizeof(ser));
  return 0;
}

