#include"double_list.h"

int main(void){
    list_t list ;
    list_init(&list);
    add_list_head(&list,1);
    add_list_head(&list,2);
    add_list_tail(&list,3);
    add_list_tail(&list,4);
    add_list_tail(&list,5);
    add_list(&list,6);
    add_list(&list,7);
    add_list(&list,8);
    add_list(&list,9);
    list_del(&list,7);
    list_traver(&list);
    list_deinit(&list);

    return 0;
}
