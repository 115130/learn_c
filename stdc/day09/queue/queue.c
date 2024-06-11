#include "queue.h"
#include<stdio.h>
#include<stdlib.h>
void queue_init(queue_t* q,int cap){
    q -> arr = malloc(sizeof(int) * cap);
    q -> size = 0;
    q -> cap = cap;
    q -> front = 0;
    q -> rear = 0;
}

void queue_deinit(queue_t* q){
    free(q -> arr);
    q -> arr = NULL;
    q -> size = 0;
    q -> cap = 0;
    q -> front = 0;
    q -> rear = 0;
}

int queue_full(queue_t* q){
    return q -> size == q -> cap;
}

int queue_empty(queue_t* q){
    return q -> size == 0;
}
