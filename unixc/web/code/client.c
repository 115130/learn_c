#include <linux/limits.h>
#include <strings.h>
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
        }else if(indentify_type(path, hres.type) == -1){
            hres.status = 404;
            strcpy(hres.desc,"NOT FOUND");
            strcat(path,root);
            strcat(path,"404.html");
        }
        struct stat s;
        if(stat(path,&s) ==-1){
            break;
        }
        hres.lenght = s.st_size;
        if (strlen(hreq.connection)) {
            strcpy(hreq.connection,hres.connction);
        }else if(strcasecmp(hreq.protocol,"http/1.0") == 0){
            strcpy(hres.connction,"close");
        }else{
            strcpy(hres.connction,"close");
        }
        
        printf("%d.%ld > 构造相应:\n",getpid(),syscall(SYS_gettid));
        char head[1024]={};
        if(construct_head(&hres, head) == -1){
            break;
        }
        
        printf("%d.%ld > 响应电文:\n%s\n",getpid(),syscall(SYS_gettid),head);
        printf("%d.%ld > 发送响应头:\n",getpid(),syscall(SYS_gettid));
        if(send_head(ca->conn, head) == -1){
            break;
        }
        
        printf("%d.%ld > 发送响应体:\n",getpid(),syscall(SYS_gettid));
        if(send_body(ca->conn, path) == -1){
            break;
        }
        if(strcasecmp(hres.connction, "close") == 0){
            break;
        }
    }
    close(ca->conn);
    free(ca);
    printf("%d.%ld > 客户机线程结束",getpid(),syscall(SYS_gettid));
    return NULL;
}

