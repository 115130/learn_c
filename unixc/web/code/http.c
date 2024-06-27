#include "http.h"
#include <strings.h>
#include <unistd.h>
#include <sys/syscall.h>
#define __USE_GNU
#include <stdio.h>
#include <string.h>
#include <time.h>

int parse_http_request(const char* req, HTTP_REQUEST* hreq){

  sscanf(req,"%s%s%s",hreq->method,hreq->path,hreq->protocol);
  //TODO 全大写
  sscanf(req,"Connction: %s\r\n",hreq->connection);
  char* connect = strcasestr(req,"connection:");
    
  printf("%d.%ld> [%s][%s][%s][%s]\n",getpid(),syscall(SYS_gettid),hreq->method,hreq->path,hreq->protocol,hreq->connection);
  if(strcmp(hreq->method,"get")){
    printf("%d.%ld>无效的方法\n",getpid(),syscall(SYS_gettid));
    return -1;
  }
  if(strcasecmp(hreq->protocol,"http/1.1") && strcasecmp(hreq->protocol,"http/1.0")){
    printf("%d.%ld>无效协议版本\n",getpid(),syscall(SYS_gettid));
    return -1;
  }
  
  return 0;
}

int construct_head(const HTTP_RESPONSE* hrsp, char* rsp){
  time_t now = time(NULL);
  char datetime[32];
  strftime(datetime,sizeof(datetime) ,"%a %d %b %Y %T" , gmtime(&now));
  sprintf(rsp,"%s %d %s\r\n"
              "Server: LEServer 1.0\r\n"
              "Date: %s\r\n"
              "Content-Type: %s\r\n"
              "Content-Length: %ld\r\n"
              "Connection: %s\r\n\r\n",
              hrsp->protocol,
              hrsp->status,
              hrsp->desc,
              datetime,
              hrsp->type,
              hrsp->lenght,
              hrsp->connction);
  return 0;
}
