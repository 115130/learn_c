#include<stdio.h>
#include"double_list.h"
#include<stdlib.h>

void list_init(list_t* list){
    //将头的prev置空,将尾的next置空,data置零
    list->head.prev=NULL;
    list->tail.next=NULL;
    list->head.data=0;
    list->tail.data=0;

    list->tail.prev=&(list->head);
    list->head.next=&(list->tail);
}
void list_deinit(list_t* list){
    node_t* first = &list->head;
    while(list -> head.next != &list->tail){
        node_t* mid = first -> next;
        node_t* last = mid -> next;
        first->next = last;
        last->prev=first;
        free(mid);
        mid = NULL;
    }
}

void add_list_head(list_t* t,int data){
    node_t* node_new = malloc(sizeof(node_t)); 
    node_new->data=data;
    node_new->next = t->head.next;
    t->head.next = node_new;
    node_new->prev = &(t -> head);
}

void add_list_tail(list_t* t,int data){
    //数据初始化
    node_t* node_new = malloc(sizeof(node_t)); 
    node_new->data=data;
    //
    node_t* node_end = t->tail.prev;
    node_end->next = node_new;
    node_new->prev = t->tail.prev;
    t->tail.prev = node_new;
    node_new->next = &(t -> tail);
}
void add_list(list_t* t,int data){
    node_t* node_new = malloc(sizeof(node_t)); 
    node_new->data=data;

    node_t* first = &(t -> head);
    node_t* mid = first -> next;
    while(mid -> data < data){
        first = mid;
        mid = mid -> next;
    }
    node_new -> prev = first -> prev;
    node_new -> next = mid -> prev;
    first -> next = node_new;
    mid -> prev = node_new;

}
void list_traver(list_t* list){
     node_t* first = &(list -> head);
    node_t* mid = first -> next;
    while(mid -> next != NULL){
        printf("%d ",mid->data);
        first = mid;
        mid = mid -> next;
    }

}

