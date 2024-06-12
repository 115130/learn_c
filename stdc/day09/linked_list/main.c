#include<stdio.h>
#include"linked.h"

int main(void){
    list_t list ;
    list_init(&list);
    head_add_node(&list,1);
    head_add_node(&list,2);
    tail_add_node(&list,3);
    tail_add_node(&list,5);
    list_add(&list,2);
    list_add(&list,101);
    list_add(&list,1);
    list_add(&list,3);
    list_add(&list,0);
    list_add(&list,1);
    list_add(&list,1);
    list_tarvel(&list);
    list_del(&list,3);
    
    list_tarvel(&list);
    return 0;

}
