#include <linux/limits.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "socket.h"
#include "http.h"
#include "client.h"
#include "resource.h"

void* client(void* arg){
    CA* ca = (CA*)arg;
    printf("%d.%ld > 客户机线程开始\n",getpid(),syscall(SYS_gettid));
    while(1){
        printf("%d.%ld > 接受请求\n",getpid(),syscall(SYS_gettid));
        char* req = recv_request(ca->conn);
        if(req == NULL){
            break;
        }
        printf("%d.%ld > 请求电文:\n%s\n",getpid(),syscall(SYS_gettid),req);
        printf("%d.%ld > 解析请求\n",getpid(),syscall(SYS_gettid));
        HTTP_REQUEST hreq = {};
        if(parse_http_request(req, &hreq) == -1){
            free(req);//解析失败释放存储请求的存储区
            break;
        }
        free(req);//解析成功后,内容结构体存储了,存储区释放
        char root[PATH_MAX+1];//资源路径
        char path[PATH_MAX+1];//真实路径

        strcpy(root,ca->home);

        if(root[strlen(root)-1] == '/'){
            root[strlen(root) -1] = '\0';
        }
        strcpy(path,root);
        strcat(path,hreq.path);
        if(strcmp(hreq.path,"/") ==0 ){
            strcat(path,"index.html");
        }
        HTTP_RESPONSE hres = {"HTTP/1.1",200,"OK","text/html"};
        if(search_resource(path) == -1){
            hres.status = 404;
            strcpy(hres.desc,"NOT FOUND");
            strcat(path,root);
            strcat(path,"404.html");
        }
        
    }
    return NULL;
}

