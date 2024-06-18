#include <unistd.h>
#include<stdio.h>
#include<unctrl.h>
#include<fcntl.h>

int main(void){
    int fd = open("./sys.txt",O_RDONLY|O_CREAT|O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }

    for(int i = 1;i<1000000;i++){
        write(fd,&i,sizeof(int));
    }
    close(fd);
    return 0;
}
