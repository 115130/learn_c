#ifndef __TASK_LIST_H__
#define __TASK_LIST_H__

    #ifndef __LIST_H__
    #define __LIST_H__
    #include"list.h"
    #endif

typedef enum {
    FINISHED,
    UNFINISHED,
}task_status_t; 

typedef struct task{
    char* task;
    task_status_t task_status;
}task_t;
#endif


