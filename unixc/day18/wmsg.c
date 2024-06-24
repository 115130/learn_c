#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<errno.h>

int main(void){
    //合成键
    printf("%d进程:合成键\n",getpid());
    key_t key = ftok(".",100);
    if(key == -1){
        perror("ftok");
        return -1;
    }

    //获取消息队列
    printf("%d进程:创建消息队列\n",getpid());
    int msg_id = msgget(key,IPC_CREAT|IPC_EXCL|0664);
    if(msg_id==-1){
        perror("msgget");
        return -1;
    }

    //接收消息
    printf("%d进程:接收消息\n",getpid());
    while(1){
        struct {
            long type;//消息类型
            char data[64];//消息内容
        }buf = {};
        
        if(msgrcv(msg_id,&buf,sizeof(buf.data)-1,1234,0) == -1){
            if(errno==EIDRM){
                printf("消息队列被销毁\n");
            }else{
                perror("msgrcv");
                return -1;
            }
        };
        printf("%ld:%s\n",buf.type,buf.data);
    }
    //销毁消息队列
    printf("%d进程:销毁消息队列\n",getpid());
    if(msgctl(msg_id,IPC_RMID,NULL) == -1){
        perror("msgctl");
        return -1;
    }
    
    printf("%d进程:大功告成\n",getpid());
    return 0;
}
