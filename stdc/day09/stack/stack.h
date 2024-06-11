#ifndef __STACK_H__
#define __STACK_H__
typedef struct stack{
    int* arr;//记录存储区首地址
    int top;//即将存入下一个元素的下标,表示容量
    int cap;//容量
}stack_t;

//栈的操作
//栈的初始化
void stack_init(int cap,stack_t* s);
void push(int,stack_t*);
int pop(stack_t*);
int stack_full(stack_t*);
int stack_empty(stack_t*);
void stack_deinit(stack_t*);
#endif //__STACK_H__
