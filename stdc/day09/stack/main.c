#include "stack.h"
#include <stdio.h>
int main(void){
    stack_t sk;
    stack_init(10,&sk);
    int data = 1;
    while(stack_full(&sk) != 1){
        push(data,&sk);
        data++;
    }

    while(stack_empty(&sk)!=1){
        printf("%d ",pop(&sk));
    }
    stack_deinit(&sk);
    return 0;
}
