#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;
typedef struct list{
    node_t* head;
    node_t* tail;
}list_t;
//初始化方法
void list_init(list_t* list);
//释放
void list_deinit(list_t* list);
//前插
void head_add(list_t* list,int data);
//后插
void tail_add(list_t* list,int data);
//顺序插入
void sque_add(list_t* list,int data);
//删除
void list_del(list_t* list,int data);
//遍历
void list_traver(list_t* list);


int main(void){
    list_t list;
    list_init(&list);
    head_add(&list,2);
    head_add(&list,1);
    tail_add(&list,6);
    tail_add(&list,4);
    sque_add(&list,5);
    list_traver(&list);
    list_del(&list,6);
    list_traver(&list);
    return 0;
}

void list_init(list_t* list){
    list->head = malloc(sizeof(list_t));
    list->tail = malloc(sizeof(list_t));
    list->head->next = list->tail;
    list->tail->next = NULL; 
}

void list_deinit(list_t* list){
    node_t* head = list -> head;
    node_t* mid = head -> next;
    do{
        free(head);
        head = mid;
    }while(mid -> next != NULL);
}

void head_add(list_t* list,int data){
    node_t* head = list->head;
    node_t* node_new = malloc(sizeof(node_t));
    node_new -> data = data;
    node_new -> next = head -> next;
    head->next = node_new;
}

void tail_add(list_t* list,int data){
    node_t* node_new = malloc(sizeof(node_t));
    node_new->data = data;
    node_t* head =list->head;
    node_t* mid = head->next;
    while(mid->next!=NULL){
        head = mid;
        mid = mid->next;
    }
    head->next = node_new;
    node_new->next = mid;
}

void sque_add(list_t* list,int data){
    node_t* node_new = malloc(sizeof(node_t));
    node_new->data = data;
    
    node_t* head = list->head;
    node_t* mid = head->next;

    while(data>mid->data&&mid->next!=NULL){
        head = mid; 
        mid = mid -> next;
    }
    head->next = node_new;
    node_new->next = mid;
}

void list_del(list_t* list,int data){
    node_t* head = list->head;
    node_t* mid = head->next;

    while(data != mid->data && mid->next != NULL){
        head = mid; 
        mid = mid -> next;
    }
    if(mid->data==data){
        head->next = mid->next;
        free(mid);
        mid = NULL;
    }
}
void list_traver(list_t* list){ 
    node_t* head = list->head;
    node_t* mid = head->next;

    while(mid->next != NULL){
        printf("%d ",mid->data);
        head = mid; 
        mid = mid -> next;
    }
    printf("\n");
}
