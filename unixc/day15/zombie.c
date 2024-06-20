#include<stdio.h>
#include<unistd.h>
int main(void){
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    if(pid == 0){
        return 0;
    }
    sleep(200);

    return 0;
}
