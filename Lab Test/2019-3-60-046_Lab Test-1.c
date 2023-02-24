#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

void Inorder(struct node *node);
struct node *Insert(struct node *node, int data);
void checkPaths(struct node *node, int array[], int length);
void printArray(int ints[], int len);
void DisplayPaths(int array[], int length);

void printPaths(struct node *node){
    int array[20];
    checkPaths(node, array, 0);
}

void checkPaths(struct node *node, int array[], int length){
    if (node == NULL){
        return;
    }
    array[length] = node->data;
    length++;
    if (node->left == NULL && node->right == NULL){
        DisplayPaths(array, length);
    }
    else{
        checkPaths(node->left, array, length);
        checkPaths(node->right, array, length);
  }
}

void DisplayPaths(int array[], int length){
    for (int i = 0; i < length-1; i++){
        printf("%d, ", array[i]);
    }
    for (int i = length-1; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

struct node *Insert(struct node *node, int data){
    if(node == NULL){
        struct node *temp = (struct node *)malloc(sizeof(struct node));
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

void Inorder(struct node *node){
    if(node == NULL){
        return;
    }
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}

int main(){
    struct node *root = NULL;
    int choice, x;
    while(1){
        printf("1. Insert\n");
        printf("2. In Order Traversal\n");
        printf("3. Print All Paths\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Input one tree element: ");
                scanf("%d", &x);
                root = Insert(root, x);
                break;
            case 2:
                printf("\nInOrder traversal: \n");
                Inorder(root);
                printf("\n\n");
                break;
            case 3:
                printf("\nPrint all root to leaf paths bellow: \n");
                printPaths(root);
                printf("\n");
                break;
            case 4:
                exit(1);
        }
    }
}
