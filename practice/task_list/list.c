#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include "task_list.h"
void list_init(list_t* list){
    task_t t = {"",CREATE};
    list->head->task = t;
    list->tail->task = t;
    list->head->next = list->tail;
    list->head->next = NULL;
}

void list_deinit(list_t* list){
}
