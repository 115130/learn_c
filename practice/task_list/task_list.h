#ifndef __TASK_LIST_H__
#define __TASK_LIST_H__

    #ifndef __LIST_H__
    #define __LIST_H__
    #include"list.h"
    #endif

typedef enum {
    CREATE,
    FINISHED,
    UNFINISHED,
}task_status_t; 

typedef struct task{
    char* task;
    task_status_t task_status;
}task_t;
void run();
void print_task();
void scnaf_task();
void del_task();
void complete_task();

#endif


