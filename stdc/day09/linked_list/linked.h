#ifndef __LINKED_H__
#define __LINKED_H__

typedef struct node{
    int data;
    struct node* next;
}node_t;

typedef struct {
    node_t* head;
    node_t* tail;
}list_t;

void list_init(list_t*);
void head_add_node(list_t*,int);
void tail_add_node(list_t*,int);
void list_deinit(list_t* l);
void print_list(list_t* l);

#endif
