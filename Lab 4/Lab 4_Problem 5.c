#include<stdio.h>
#include<stdlib.h>

struct node{
    char val;
    struct node *next;
} *front = 0, *rear = 0;

void enqueue(char b){
    struct node *newNode;
    newNode = (struct node *)malloc (sizeof(struct node));
    newNode->val = b;
    newNode->next = NULL;
    if(front == 0 && rear == 0){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void print_queue(){
    printf("Output is: ");
    struct node *temp;
    temp = front;
    while(temp!=0){
        printf("%c", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    char y[50];
    printf("Insert string: ");
    gets(y);
    for(int i = 0; y[i] != NULL; i++){
        if(y[i] != ' '){
            enqueue(y[i]);
        }
    }
    print_queue();
    return 0;
}
