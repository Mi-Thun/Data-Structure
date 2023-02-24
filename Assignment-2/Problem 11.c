#include <stdio.h>
#include <stdlib.h>

struct tNode{
    int data;
    struct tNode *left, *right;
};

int height(struct tNode *node){
    if(node == NULL)
        return 0;
    else{
        int leftSide;
        int rightSide;
        leftSide = height(node -> left);
        rightSide = height(node -> right);
        if(leftSide > rightSide){
            return leftSide + 1;
        }
        else
            return rightSide + 1;
        }
}

struct tNode *Insert(struct tNode *node, int data){
    if(node == NULL){
        struct tNode *temp;
        temp = (struct tNode *)malloc(sizeof(struct tNode));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(data > (node->data)){
        node->right = Insert(node->right, data);
    }
    if(data < node->data){
        node->left = Insert(node->left, data);
    }
    return node;
}

int main(){
    printf("Input array size: ");
    struct tNode *root = NULL, *temp;
    int choice, x, y,N;
    scanf("%d", &N);
    int array[N];
    printf("Input array value: ");
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        array[i] = x;
        root = Insert(root, x);
    }
    int h = height(root)-1;
    printf("Height of this tree is: %d\nThank you...!!", h);

}
