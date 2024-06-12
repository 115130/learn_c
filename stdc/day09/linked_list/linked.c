#include<stdio.h>
#include<stdlib.h>
#include"linked.h"
void list_init(list_t* list){
    list -> head = malloc(sizeof(node_t));
    list -> tail = malloc(sizeof(node_t));
    list -> head -> data = 0; 
    list -> tail -> data = 0;
    list -> head -> next = list -> tail;
    list -> tail = NULL;
}

void list_deinit(list_t* list){
    node_t* pnode = list->head;
    do{
        node_t* next = pnode->next;
        free(pnode);
        pnode = next;
    }while(pnode != NULL);
    list -> head = NULL; 
    list -> tail = NULL; 
}

void head_add_node(list_t* list,int data){
    //给节点分配内存和赋值
    node_t* node = malloc(sizeof(node_t));
    node -> data = data;
    //先暂存第一个有效节点
    node_t* first_node = list -> head -> next;
    //将节点的指向的第一个
    node -> next = first_node;
    //将头节点指向新建的节点
    list -> head -> next = node;
}
void tail_add_node(list_t* list,int data){
    //给新节点分配内存和值
    node_t* node = malloc(sizeof(node_t));
    node -> data = data;
    //
    node_t* pnode = list -> head;
    node_t* tmp;
    //找到最后一个有效节点
    while(tmp -> next != NULL){//此时的tmp是尾节点
        pnode = tmp;
        tmp = pnode->next;
    }
    pnode -> next = node;
    node -> next = tmp;
}

void print_list(list_t* list){
    //得到头节点
    node_t* pnode = list -> head;
    node_t* tmp = list -> head -> next;

    while(tmp -> next != NULL){ 
        pnode = tmp;
        printf("%d ",pnode -> data);
        tmp = pnode->next;
    }
 
}
