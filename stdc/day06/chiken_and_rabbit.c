//从命令行读取参数完成用户是sunwukong,密码是123456的用户登录
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
int main(int argc, char* argv []){
    int foot_count = 0;
    int count = 0;
    for (int i = 0;i < argc; i++){
        //-u后面跟sorghum,-p后面跟密码
        if(strcmp("-f",argv[i]) == 0){
           char *foot_count_str = argv[i + 1];
           foot_count = atoi(foot_count_str);
        }else if(strcmp("-c",argv[i]) == 0){
           char *count_str = argv[i + 1];
           count = atoi(count_str);
        }

    }
    for(int i = 0;i < count;i++){
        for(int j = 0;j < count;j++){
            if(i+j==count && (i *4+j*2)==foot_count){
                printf("鸡有%d只,兔有%d只",i,j);
                return 0;
            }
        }
    }

    return 0;
}
