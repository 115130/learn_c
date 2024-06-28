#ifndef __CLIENT_H__
#define __CLIENT_H__
typedef struct client_args{
    int conn;
    const char* home;//资源路径
}CA;

void* client(void* arg);

#endif
