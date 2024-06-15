#include <stdint.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prve;
}node_t;

typedef struct list{
    node_t* head;
    node_t* tail;
}list_t;

void list_init(list_t* t){
    t->head = malloc(sizeof(node_t));
    t->tail = malloc(sizeof(node_t));
    t->head->data=0;
    t->tail->data=0;
    t->head->prve = NULL;
    t->tail->next = NULL;
    t->head->next = t->tail;
    t->tail->prve = t->head;

}

void list_deinit(list_t* list){
    node_t* mid;
    while(list->head->next!=list->tail){
        mid = list->head->next;
        list->head->next = mid->next;
        free(mid);
    }
    free(list->head);
    list->head=NULL;
    free(list->tail);
    list->tail=NULL;
}
void front_add(list_t* list,int data){
    node_t* node_new = malloc(sizeof(node_t));
    node_new -> data = data;
    
    node_t* mid = list->head->next;
    
    mid->prve = node_new;
    list->head->next = node_new;
    node_new->prve = list->head;
    node_new -> next = mid;
}
void  tail_add(list_t* list,int data){
    node_t* node_new = malloc(sizeof(node_t));
    node_t* prve = list->tail->prve;
    node_new->data = data;

    prve->next = node_new;
    node_new->prve=prve;
    node_new->next=list->tail;
    list->tail->prve=node_new;

}
void sque_add(list_t* list,int data){
    node_t* node_new = malloc(sizeof(node_t));
    node_t* prve = list->head;
    node_t* mid = prve->next;
    node_new->data = data;
    while(mid->data!=data&&mid->next!=NULL){
        prve = mid;
        mid=mid->next;
    }
    prve->next = node_new;
    node_new->prve = prve;
    node_new->next = mid;
    mid->prve = prve;
}
void list_tra(list_t* list){
    node_t* prve = list->head;
    node_t* mid = prve->next;
    while(mid->next!=NULL){
        printf("%d ",mid->data);
        prve = mid;
        mid=mid->next;
    }
    printf("\n");

}
void list_del(list_t* list,int data){
    node_t* prve = list->head;
    node_t* mid = prve->next;
    while(mid->data!=data&&mid->next!=NULL){
        prve = mid;
        mid=mid->next;
    }
    if(mid->next!=NULL){
        prve->next=mid->next;
        mid->next->prve=prve;
    }
}

int main(void){
    list_t list;
    list_init(&list);
    front_add(&list,1);
    front_add(&list,2);
    tail_add(&list,3);
    tail_add(&list,4);
    tail_add(&list,5);
    sque_add(&list,6);
    sque_add(&list,3);
    sque_add(&list,7);
    sque_add(&list,8);
    sque_add(&list,9);
    list_tra(&list);
    list_del(&list,3);
    list_tra(&list);
    list_deinit(&list);
    return 0;
}
