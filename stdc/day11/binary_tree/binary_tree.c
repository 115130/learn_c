#include <bits/pthreadtypes.h>
#include <stdint.h>
#include<stdlib.h>
#include<stdio.h>
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
        p1 = p2;
        if(data>p1 -> data){
            p2 = p2 -> right;
        }else {
            p2 = p2 -> left;
        }
    }while(p2 != NULL);

    if(data > p1->data){
        p1 -> right = new ;
    }else if(data < p1->data){
        p1 -> left = new;
    }
    t->cnt++;
}

void front(node_t* t){
    if(t==NULL){
        return;
    }
    front(t->left);
    front(t->right);

}

void tree_del(tree_t* t,int data){
    node_t* ptar = t -> root;
    node_t* pnode = t -> root;
    while(ptar -> data != data && ptar != NULL){
        pnode = ptar;
        if(data > ptar->data){
            ptar = ptar ->right;    
        }else {
            ptar = ptar -> left;
        }
    }
    
    if(ptar == NULL){
        printf("没找到删除的节点");
        return;
    }
    node_t* left = ptar->left;
    node_t* right = ptar->right;

    //目标节点左右子树都没有
    if(left == NULL && right == NULL){
        if(ptar->data > pnode->data){
            pnode -> right = NULL;
        }else{
            pnode -> left = NULL;
        }
        free(ptar);
        ptar = NULL;
        t -> cnt--;
    }
    if(left==NULL && right!=NULL){
        if(ptar -> data < pnode->data){
            pnode->left = right;
        }else{
            pnode->right = right;
        }
        free(ptar);
        ptar = NULL;
        t->cnt--;
    }
    if(left!=NULL && right==NULL){
        if(ptar -> data < pnode->data){
            pnode->left = left;
        }else {
            pnode->right = left;
        }
        free(ptar);
        ptar = NULL;
        t->cnt--;

    }

    if(left!=NULL&&right!=NULL){
        node_t* p1,*p2;
        p1 = p2 = right;
        while(p2!= NULL){
            p1 = p2;
            p2 = p2 -> left;
        }
        //将左字数挂在右子树
        p1->left=left;
        //新树挂在父节点的判断
        if(ptar -> data < pnode->data){
            pnode->left = right;
        }else {
            pnode->right = right;
        }
        free(ptar);
    }
    

}

void tree_first(node_t* n){
    if(n==NULL)return;
    printf("%d ",n->data);
    tree_first(n->left);
    tree_first(n->right);
}

void tree_mid(node_t* n){
    if(n==NULL)return;
    tree_mid(n->left);
    printf("%d ",n->data);
    tree_mid(n->right);
}

void tree_last(node_t* n){
    if(n==NULL)return;
    tree_last(n->left);
    tree_last(n->right);
    printf("%d ",n->data);
}
