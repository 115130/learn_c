#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node_t;
typedef struct list
{
    node_t head;
    node_t tail;
}list_t;

void list_init(list_t*);
void list_deinit(list_t*);

#endif