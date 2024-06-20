#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void){
    int status = system("./new");
    if(status == -1){
        perror("system");
        return -1;
    }

    if(WIFSIGNALED(status)){
        printf("异常终止%d\n",WTERMSIG(status));
    }else{
        printf("正常终止%d\n",WEXITSTATUS(status));
    }
    int status1 = system("ls -al");
    if(status1 == -1){
        perror("system");
        return -1;
    }

    if(WIFSIGNALED(status1)){
        printf("异常终止%d\n",WTERMSIG(status1));
    }else{
        printf("正常终止%d\n",WEXITSTATUS(status1));
    }

    

    return 0;
}
