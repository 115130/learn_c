#include<stdio.h>
#include"linked.h"

int main(void){
    list_t list ;
    list_init(&list);
    head_add_node(&list,1);
    head_add_node(&list,2);
    tail_add_node(&list,3);
    print_list(&list);
    return 0;

}
