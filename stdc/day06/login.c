//从命令行读取参数完成用户是sunwukong,密码是123456的用户登录
#include<stdio.h>
#include <string.h>
#define USERNAME ("sunwukong")
#define PASSWORD ("123456")

int main(int argc, char* argv []){
    int flag = 0;
    for (int i = 0;i < argc; i++){
        //-u后面跟用户名,-p后面跟密码
        if(strcmp("-u",argv[i]) == 0){
            strcmp(USERNAME, argv[i + 1]) == 0?flag+=1:0;//懒的写if写个3元,0没有意义
        }else if(strcmp("-p",argv[i]) == 0){
            strcmp(PASSWORD, argv[i + 1]) == 0?flag+=1:0;//懒的写if写个3元,0没有意义
        }
    }
    if(flag == 2){
        printf("登录成功");
    }else{
        printf("登录失败");
    }
    return 0;
}
