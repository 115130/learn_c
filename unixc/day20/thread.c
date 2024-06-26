#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

void* run(void * arg){
    printf("%lu线程:我是子线程\n",pthread_self());
    printf("%lu线程:%s\n",pthread_self(),(char*)arg);
    return NULL;
}

int main(void){
    printf("%lu线程:我是主线程\n",pthread_self());

    pthread_t  tid;
    int error = pthread_create(&tid,NULL,run,"hello");
    if(error){
        fprintf(stderr,"pthread_create:%s\n",strerror(error));
        return -1;
    }
    sleep(1);
    return 0 ;
}
