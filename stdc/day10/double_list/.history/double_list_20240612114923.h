#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__
typedef struct list{
    int data;
    struct list* next;
    struct list* prev;
    
}list_t;
#endif