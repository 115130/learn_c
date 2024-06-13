#include"binary_tree.h"
#include<stdlib.h>
int main(void){
    tree_t t;
    tree_init(&t);
    for(int i = 0;i<20;i++ ){
        int a =rand()%100;
        tree_insert(&t,a);
    }
    int a = 1+1;
    a++;
    return 0;
}