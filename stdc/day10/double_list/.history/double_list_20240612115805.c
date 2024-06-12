#include<stdio.h>
#include"double_list.h"
#include<stdlib.h>

void list_init(list_t* list){
    //将头的prev置空,将尾的next置空,data
    list->head.prev=NULL;
    list->tail.next=NULL;
    list->head.data=0;
    list->tail.data=0;

    list->tail.prev=&(list->head);
    list->head.next=&(list->tail);
}