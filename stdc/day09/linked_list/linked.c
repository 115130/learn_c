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

void add_node(list_t* list,int data){
    //node_t node = malloc(sizeof(node_t));
    //node.data = data;
    
}
