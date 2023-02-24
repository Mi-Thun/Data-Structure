#include <stdio.h>
#include <stdlib.h>
#define bool int

struct node {
  int item;
  struct node *left;
  struct node *right;
};

struct node *newNode(int item) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->item = item;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

bool checkHeightBalance(struct node *root, int *height) {
  int leftHeight = 0, rightHeight = 0;
  int x = 0, y = 0;

  if (root == NULL) {
    *height = 0;
    return 1;
  }

  x = checkHeightBalance(root->left, &leftHeight);
  y = checkHeightBalance(root->right, &rightHeight);

  *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

  if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2)){
    return leftHeight - rightHeight;
  }
  else{
    return leftHeight-rightHeight && leftHeight-rightHeight;
  }
}

void eachNodeCheckHeightBalance(struct node *node){
    int height = 0;
    if(node == NULL){
        return;
    }
    eachNodeCheckHeightBalance(node->left);
    eachNodeCheckHeightBalance(node->right);
    printf("Node value %d height is: %d\n", node->item, checkHeightBalance(node, &height));
}

int main() {
  int height = 0;
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(9);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->left->right = newNode(10);

  eachNodeCheckHeightBalance(root);

  if (checkHeightBalance(root, &height)){
    printf("The tree is balanced");
  }
  else{
    printf("The tree is not balanced");
  }
}
