#include<stdio.h>
#include"double_list.h"
#include<stdlib.h>

void list_init(list_t* list){
    list->head.prev=NULL;
    list->tail.next=NULL;
    list->tail.prev=&(list->head);
    list->tail.prev=&(list->);
}