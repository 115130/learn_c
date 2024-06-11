#ifndef __QUEUE_h__
#define __QUEUE_h__
typedef struct queue{
    int* arr;
    int size;
    int cap;
    int front;//出队元素
    int rear;//入队元素
}queue_t;

//队列初始化
void queue_init(queue_t* q,int cap);
void queue_deinit(queue_t* q);
int queue_full(queue_t* q);
int queue_empty(queue_t* q);


#endif
