//#创建新进程,取代旧进程
#include<stdio.h>
#include<unistd.h>

int main(void){
    printf("%d进程,我要变身了\n",getpid());
    //if(execl("./new","test","dasdsa") == -1){
      //  perror("execl");
      //  return -1;
    //}
   /* if(execlp("ls","-al","--color=auto",NULL) == -1){
        perror("execlp");
        return -1;
    }*/
    char* envp[] = {"NAME = 刘亦菲", "AGE = 18","FOOD=锅包肉",NULL};
    if(execle("./new","new","hello",NULL,envp) == -1){
        perror("execle");;
        return -1;
    };
    printf("%d进程变身成功力\n",getpid());

    return 0;
}
