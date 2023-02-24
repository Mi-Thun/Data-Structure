#include <stdio.h>
#include <stdlib.h>

struct tNode{
    int data;
    struct tNode *left, *right;
};

struct tNode *search(struct tNode *node, int z){
    if(node == NULL){
        return NULL;
    }
    if(z > node->data){
        return search(node->right, z);
    }
    if(z < node->data){
        return search(node->left, z);
    }
}

struct tNode *FinMin(struct tNode *node){
    if(node->left != NULL){
        return FinMin(node->left);
    }
    else{
        return node;
    }
}

struct tNode *FinMax(struct tNode *node){
    if(node->right != NULL){
        return FinMax(node->right);
    }
    else{
        return node;
    }
}

struct tNode *Delete(struct tNode *node, int x){
    struct tNode *temp;
    if(node == NULL){
        printf("element not found");
    }
    else if(x < node->data){
        node->left = Delete(node->left, x);
    }
    else if(x > node->data){
        node->right = Delete(node->right, x);
    }
    else{
        if(node->right != NULL && node->left != NULL){
            temp = FinMin(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
        else{
            temp = node;
            if(node->left==NULL){
                node = node->right;
            }
            else if(node->right == NULL){
                node = node->left;
            }
        }
    }
    return node;
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

void Postorder(struct tNode *node){
    if(node == NULL){
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->data);
}

void Inorder(struct tNode *node){
    if(node == NULL){
        return;
    }
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}

void Preorder(struct tNode *node){
    if(node == NULL){
        return;
    }
    printf("%d ", node->data);
    Preorder(node->left);
    Preorder(node->right);
}

int main(){
    struct tNode *root = NULL, *temp;
    int choice, x, y;
    while(1){
        printf("    =>> MENU <<=    \n");
        printf("1. Insert\n");
        printf("2. Pre Order\n");
        printf("3. Post Order\n");
        printf("4. In Order\n");
        printf("5. Max\n");
        printf("6. Min\n");
        printf("7. Deleted\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Input element: ");
                scanf("%d", &x);
                root = Insert(root, x);
                break;
            case 2:
                printf("PreOrder: ");
                Preorder(root);
                printf("\n");
                break;
            case 3:
                printf("PostOrder: ");
                Postorder(root);
                printf("\n");
                break;
            case 4:
                printf("InOrder: ");
                Inorder(root);
                printf("\n");
                break;
            case 5:
                printf("MAX: %d", FinMax(root)->data);
                printf("\n");
                break;
            case 6:
                printf("MIN: %d", FinMin(root)->data);
                printf("\n");
                break;
            case 7:
                printf("Enter element to deleted: ");
                scanf("%d", &y);
                root = Delete(root, y);
                printf("Element deleted..!!\n");
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &y);
                temp = search(root, y);
                if(temp == NULL){
                    printf("Not found..!!\n");
                }
                else
                    printf("Element found..!!\n");
                break;
            case 9:
                exit(1);
        }
    }
}
