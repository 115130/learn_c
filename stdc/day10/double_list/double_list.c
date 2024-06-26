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

    node_t* first_node = t -> head.next;

    //更新头指针
    t -> head.next = node_new;
    //更新第一个指针
    first_node->prev = node_new;
    //将插入的指针头尾加入新的node
    node_new -> next = first_node;
    node_new -> prev = &(t -> head);
}

void add_list_tail(list_t* t,int data){
    //数据初始化
    node_t* node_new = malloc(sizeof(node_t)); 
    node_new->data=data;
    //
    node_t* node_end = t->tail.prev;

    node_end->next = node_new;
    t->tail.prev = node_new;
    //更新新node的前后关系
    node_new->prev = node_end;
    node_new->next = &(t -> tail);
}

void list_del(list_t* list,int data){
    node_t* first = list -> head.next; 
    node_t* mid = first -> next; 
    while(mid->data != data && mid->next!=NULL){
        first = mid;
        mid = mid -> next;
    }
    if(mid!=&(list->tail)){
        node_t* last = mid->next;
        free(mid);
        first->next = last;
        last->prev = first;
    }

}

void add_list(list_t* t,int data){
    node_t* node_new = malloc(sizeof(node_t)); 
    node_new->data=data;

    node_t* first = &(t -> head);
    node_t* mid = first -> next;
    while(mid -> data <data && mid->next!=NULL){
        first = mid;
        mid = mid -> next;
    }

    node_new -> prev = first;
    node_new -> next = mid;
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

