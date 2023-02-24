#include<stdio.h>
#include<stdlib.h>

struct node{
    int *data;
    struct node *left, *right;
};

struct node *create(int *data){
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void print(struct node *node, int level){
    if(node == NULL)
        return;
    for(int i = 0; i < level - 1; i++)
        printf("    ");
        printf("%d :", level);
        printf("%d\n", node->data);
    print(node->left, level + 1);
    print(node->right, level + 1);
}

struct node *addNode(){
    struct node *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->right->left = create(6);
    root->right->right = create(7);
    root->left->left->left = create(8);
    root->left->left->left->right = create(9);
    return root;
}
int main(){
    struct node *root = addNode();
    print(root, 1);
    return 0;
}
