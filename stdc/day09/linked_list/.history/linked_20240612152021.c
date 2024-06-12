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
    node_t* node_new = malloc(sizeof(node_t));
    node_new -> data = data;
    //先暂存第一个有效节点
    node_new -> next= list -> head -> next;
    //将头节点指向新建的节点
    list -> head -> next = node_new;
}

void tail_add_node(list_t* list,int data){
    //给新节点分配内存和值
    node_t* node_new = malloc(sizeof(node_t));
    node_new -> data = data;
    //
    node_t* pnode = list -> head;
    node_t* tmp = pnode -> next;
    //找到最后一个有效节点
    while(tmp -> next != NULL){//此时的tmp是尾节点
        pnode = tmp;
        tmp = pnode->next;
    }
    pnode -> next = node_new;
    node_new -> next = tmp;
}

void list_add(list_t* list,int data){
    node_t* node_new = malloc(sizeof(node_t));
    node_new -> data = data;
    node_t* first = list -> head;
    node_t* mid = first -> next;
    while(mid -> data < data && mid -> next!=NULL){
        first = mid;
        mid = mid -> next;
    }
    first -> next = node_new;
    node_new -> next = mid;
}

void list_del(list_t* list,int data){
    node_t* first = list -> head;
    node_t* mid = first -> next;
    while(mid -> data != data&&mid->next!=NULL){
        first = mid;
        mid = mid -> next;
    }
    if(mid!=list->tail){
        node_t* last = mid -> next; 
        free(mid);
        first->next=last;
    }
}




void list_tarvel(list_t* list){
    //得到头节点

    for(node_t* pnode = list->head, *tmp = pnode->next;tmp->next!=NULL;tmp = pnode->next){
        pnode = tmp;
        printf("%d ",pnode->data);

    }
    printf("\n");
    //while(tmp -> next != NULL){ 
      //  pnode = tmp;
        //printf("%d ",pnode -> data);
       // tmp = pnode->next;
    //}
 
}
