#ifndef __SOCKET_H__
#define __SOCKET_H__
  
  int init_socket(short port);
  int accept_client(void);
  char* recv_request(int conn);
  int send_head(int conn,const char* head);
  int send_body(int conn,const char* path);
  void deinit_socket(void);
  
#endif
