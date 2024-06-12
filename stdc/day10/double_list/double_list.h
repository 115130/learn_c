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
void add_list_head(list_t* t,int data);            
void add_list_tail(list_t* t,int data);            
void add_list(list_t* t,int data);
void list_traver(list_t* list);
#endif
