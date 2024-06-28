#include "resource.h"
#include "mime.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
int search_resource(const char* path){
    printf("apthhhhh");
    return access(path, R_OK);
}

int indentify_type(const char* path, char* type){
    //切割字符串,strr 代表逆向
    char* suffix =  strrchr(path,'.');
    if(suffix == NULL){
        return -1;
    }
    for(int i = 0;i < sizeof(s_mime)/sizeof(s_mime[0]);i++){
        if(strcasecmp(suffix,s_mime[i].suffix) == 0){
            strcpy(type,s_mime[i].type);
            return 0;
        }
    }
    printf("%d.%ld > 未识别扩展类型\n",getpid(),syscall(SYS_gettid));
    return -1;
}
