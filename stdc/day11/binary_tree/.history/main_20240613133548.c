#include"binary_tree.h"
#include<stdlib.h>
#include<stdio.h>
int main(void){
    tree_t t;
    tree_init(&t);
    for(int i = 0;i<20;i++ ){
        int a =rand()%100;
        tree_insert(&t,a);
    }
    tree_first(t.root);
    printf("\n");
    tree_mid(t.root);
    printf("\n");
    tree_last(t.root);
    printf("\n");
    return 0;
}
