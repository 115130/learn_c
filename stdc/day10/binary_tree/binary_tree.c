#include<stdlib.h>
#include"binary_tree.h"

void tree_init(tree_t* t){
    t -> root = NULL;
    t -> cnt = 0;
}
void tree_insert(tree_t* t,int data){
    //创建新节点
    node_t* new = malloc(sizeof(node_t));
    new -> data = data;
    new -> left = NULL;
    new -> right = NULL;
    //给新节点找位置
    if(t -> root == NULL){
        t -> root = new;
        t -> cnt++;
        return;
    }
    node_t* p1 = t -> root;
    node_t* p2 = t -> root;
    do{
        if(data>p1 -> data){
            p2 = p2 -> right;
        }else if(data<p1->data){
            p2 = p2 -> left;
        }
        if(p2!=NULL){
            p1 = p2;
        }
    }while(p2 != NULL);

    if(data > p1->data){
        p1 -> right = new ;
    }else if(data < p1->data){
        p1 -> left = new;
    }
}

void front(node_t* t){
    if(t==NULL){
        return;
    }
    front(t->left);
    front(t->right);

}


