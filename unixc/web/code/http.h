#ifndef __HTTP_H__
#define __HTTP_H__
#include <limits.h>
#include <sys/types.h>
//存储解析得到的关键数据
typedef struct http_request{
  char method[32];//请求方式
  char path[PATH_MAX + 1];//资源路径
  char protocol[32];//协议版本
  char connection[32];//连接状态
}HTTP_REQUEST;

typedef struct http_respose{
  char protocol[32];//协议
  int status;//状态
  char desc[64];//状态描述
  char type[64];//类型
  off_t lenght;//长度
  char connction[32];//连接状态
}HTTP_RESPONSE;


int parse_http_request(const char* request,HTTP_REQUEST* hreq);

//构造响应头
int construct_head(const HTTP_RESPONSE* hres,char* head);

#endif
