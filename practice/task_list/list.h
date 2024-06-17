#ifndef __LIST_H__
#define __LIST_H__
#ifndef __TASK_LIST_H__
    #include "task_list.h"
    #define __TASK_LIST_H__
    #endif
typedef struct node{
    task_t task;
    struct node* next;
}node_t;

typedef struct list{
    node_t* head;
    node_t* tail;
}list_t;

void list_init(list_t* list);
void list_deinit(list_t* list);
void list_add(list_t* list,task_t task);
void list_head_add(list_t* list,task_t task);
void list_tail_add(list_t* list,task_t task);
void printf_task(list_t* list);
void list_del(list_t* list);
#endif
