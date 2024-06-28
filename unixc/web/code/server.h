#ifndef __SERVER_H__
#define __SERVER_H__
int init_server(short port);
int run_server(const char* home);
void deinit_server();
#endif
