#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include<unistd.h>
int global = 10;
int main(void){
    int local = 20;
    int* heap = malloc(sizeof(int));
    *heap = 30;
    pid_t pid = fork();
    sleep(1);
    printf("%d 进程:%p:%d %p:%d %p:%d\n",getpid(),&global,global,&local,local,heap,++*heap);
    if(pid==-1){
        perror("fork");
        return -1;
    }
    sleep(1);
    if(pid == 0){
        printf("%d 子进程:%p:%d %p:%d %p:%d\n",getpid(),&global,global,&local,local,heap,++*heap);
        return 0;
    }
    sleep(1);
    printf("%d 进程:%p:%d %p:%d %p:%d\n",getpid(),&global,global,&local,local,heap,++*heap);
    return 0;
}
