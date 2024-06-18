#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char** argv){
    printf("文件%s ",argv[1]); 
    //判断文件是否存在
    if(access(argv[1],F_OK) == 0){   
        //判断可读不可读
        if(access(argv[1],R_OK) == 0){ 
            printf("可读  ");
        } else{
            printf("不可读  ");
        }
        //判断可写不可写
        if(access(argv[1],W_OK) == 0){ 
            printf("可写  ");
        } else{
            printf("不可写  ");
        }
        //判断是否可执行
        if(access(argv[1],X_OK) == 0){ 
            printf("可执行  ");
        } else{
            printf("不可执行  ");
        }
    } else{
        printf("不存在  ");
    }
    
}
