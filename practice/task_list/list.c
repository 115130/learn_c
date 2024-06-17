#include<stdio.h>
#include<stdlib.h>
#pragma  once
#include"list.h"
#include "task_list.h"
void list_init(list_t* list){
    list->head = malloc(sizeof(node_t));
    list->tail = malloc(sizeof(node_t));
    task_t t = {"",CREATE};
    list->head->task = t;
    list->tail->task = t;
    list->head->next = list->tail;
    list->head->next = NULL;
}

void list_deinit(list_t* list){
    node_t* first = list->head;
    node_t* mid =first->next;
    free(first);
    while(mid->next!=NULL){
        first = mid;
        mid = mid->next;
        free(first);
    }    
}

void list_head_add(list_t* list,task_t task){
    node_t* node_new = malloc(sizeof(node_t));
    node_new->task = task;
    node_t* head = list->head;
    node_t* mid = list->head->next;
    head->next = node_new;
    node_new->next = mid;
}

