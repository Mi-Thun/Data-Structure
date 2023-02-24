#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
} *top = NULL, *newNode;

struct node{
    int val;
    struct node *next1;
} *front = 0, *rear = 0, *newNode1;

void enqueue(int j){
    newNode1 = (struct node *)malloc (sizeof(struct node));
    newNode1->val = j;
    newNode1->next1 = NULL;
    if(front == 0 && rear == 0){
        front = newNode1;
        rear = newNode1;
    }
    else{
        rear->next1 = newNode1;
        rear = newNode1;
    }
}

void print_queue(){
    struct node *temp1;
    temp1 = front;
    while(temp1!=0){
        printf("%d ", temp1->val);
        temp1 = temp1->next1;
    }
}

void create(int a){
    int x, i;
    printf("Enter S1: ");
    for(i = 0; i < a; i++){
        scanf("%d", &x);
        newNode = (struct stack *)malloc(sizeof(struct stack));
        newNode->data = x;
        if(top == NULL){
            newNode->next = NULL;
            top = newNode;
        }else{
            newNode->next = top;
            top = newNode;
        }
    }
}

int pop(){
    struct stack *temp;
    while(top != NULL){
        temp = top;
        enqueue(temp->data);
        top = top->next;
        free(temp);
    }
}

int main(){
    int y;
    printf("How many node you want to create: ");
    scanf("%d", &y);
    create(y);
    pop();
    printf("Result Q1: ");
    print_queue();
    return 0;
}
