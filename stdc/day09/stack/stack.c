#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void stack_init(int cap,stack_t* s){
    s -> arr = malloc(sizeof(int) * cap);
    s -> cap = cap;
    s -> top = 0;
}

void push(int elment,stack_t* s){
    s->arr[s->top] = elment;
    s->top++;
}

void stack_deinit(stack_t* s){
    free(s -> arr);
    s -> arr = NULL;
    s -> top = 0;
    s -> cap = 0;
}

int stack_full(stack_t * s){
    if(s->top==s->cap){
        return 1;
    }
    return 0;
}

int stack_empty(stack_t * s){
    if(s->top == 0){
        return 1;
    }
    return 0;
}

int pop(stack_t* s){
    return s->arr[--(s->top)];
}
