#include "server.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "socket.h"
#include "client.h"
#include "singals.h"

int init_server(short port){
    if(init_signals()){
        return -1;
    }
    if(init_socket(port) == -1){
        return -1;
    }
    return 0;
}

int run_server(const char* home){
    while(1){
        int conn = accept_client();
        if(conn == -1){
            return -1;
        }
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

        CA* ca = malloc(sizeof(CA));
        ca->conn = conn;
        ca->home = home;
        int err = pthread_create(&tid, &attr, client, ca);
        if(err){
            fprintf(stderr,"pthead_creat:%s\n",strerror(err));
            return -1;
        }
    }
    return 0;
}

void deinit_server(void){
    deinit_socket();
}
