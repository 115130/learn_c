#include<stdio.h>
#include"queue.h"

int main(void){
    queue_t qu;
    queue_init(&qu,10);
    int in = 1;
    while(queue_full(&qu)==0){
        queue_push(&qu,in);
        in++;
    }
    while(queue_empty(&qu)==0){
        printf("%d ",queue_pop(&qu));
    }
    printf("\n");
    queue_deinit(&qu);
    return 0;
}
