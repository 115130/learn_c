#include<stdio.h>
#include<stdlib.h>
#include <string.h>
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
void list_tail_add(list_t* list,task_t task){
    node_t* node_new = malloc(sizeof(node_t));
    node_new->task = task;
    node_t* first  = list->head;
    node_t* mid  = first->next;
    while(mid->next!=NULL){
        first= mid;
        mid = mid->next;
    }
    first->next = node_new;
    node_new->next = mid;

}

void list_del(list_t* list,task_t task){
    node_t* first  = list->head;
    node_t* mid  = first->next;

    while(strcmp(task.task,mid->task.task)&&task.task_status == mid->task.task_status && mid->next!=NULL){
        first = mid;
        mid = mid->next;
    }
    first->next = mid->next;
    if(mid->next!=NULL){
        free(mid);
    } 
}
void printf_task(list_t* list){
    node_t* first  = list->head;
    node_t* mid  = first->next;

    while(mid->next!=NULL){
        first = mid;
        printf("\t%s\t%s",mid->task.task,mid->task.task_status==FINISHED?"已完成":"未完成");
        mid = mid->next;
    }

}
