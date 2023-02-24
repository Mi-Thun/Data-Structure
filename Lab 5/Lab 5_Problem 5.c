#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
} *head = NULL;

void insert(int num) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = head;
    head = newNode;
}

void reverse(struct node* newNode1) {
    if (newNode1 == NULL)
       return;
    if(newNode1->next == NULL){
        head = newNode1;
        return;
    }
    reverse(newNode1->next);
    newNode1->next->next = newNode1;
    newNode1->next = NULL;
}

void display(struct node *newNode1) {
  while (newNode1 != NULL) {
     printf("%d    ", newNode1->data);
     newNode1 = newNode1->next;
  }
}

int main() {
    while(1){
        int x, y;
        printf("         ==> MENU <==         \n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("..............................\n");
        printf("Choice number between (1-3): ");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("Enter element: ");
                scanf("%d", &y);
                insert(y);
                break;
            case 2:
                printf("        ==> RESULT <==      \nMy linked list\n");
                display(head);
                reverse(head);
                printf("\nReversed linked list\n");
                display(head);
                printf("\n");
                break;
            case 3:
                exit(1);
        }
    }
}
