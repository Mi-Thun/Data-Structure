#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next, *prev;
} * head = NULL, *tail = NULL, *curr;

void createList(int n);
void displayList();

int main(){
    int x, i, N;
    printf("Enter number of node to create: ");
    scanf("%d", &x);
    printf("Enter node value: ");
    createList(x);

    printf("Enter N to  to rotate the linked list counter-clockwise: ");
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        insert_at_end(delete_at_beginning());
    }
    printf("Result is: ");
    displayList();
    return 0;
}

void createList(int n){
    int i;
    for(i = 0; i < n; i++){
        curr = (struct node *) malloc(sizeof(struct node));
        scanf("%d", &(curr -> val));
        curr -> next = NULL;
        curr -> prev = NULL;
        if(head == NULL){
            head = curr;
            tail = curr;
        } else{
            struct node *temp;
            temp = tail;
            temp->next = curr;
            curr->prev= temp;
            tail = curr;
        }
    }
}

void displayList(){
    struct node *temp = head;
    while (temp != NULL){
        printf("%d  ", temp->val);
        temp = temp->next;
    }
}

void insert_at_end(int a){
    struct node *temp;
     curr = (struct node *) malloc(sizeof(struct node));
     curr -> val = a;
     curr->next = NULL;
     curr->prev = NULL;
     if(head == NULL){
            head = curr;
            tail = curr;
    } else{
        temp = head;
        while(temp-> next!=NULL){
            temp = temp -> next;
        }
        temp -> next = curr;
        curr->prev = temp;
        tail = curr;
    }
}

int delete_at_beginning(){
    int z;
    struct node *temp;
    temp = head;
    head = head->next;
    head->prev = NULL;
    z = temp->val;
    free(temp);
    return z;
}
