#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node_t;

typedef struct tree{
    node_t* root;
    int cnt;
}tree_t;

void tree_init(tree_t * t);
void tree_insert(tree_t* t,int data);
void tree_del(tree_t* t,int data);
#endif
