#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
} *front = 0, *rear = 0;

struct node2{
    int val2;
    struct node2 *next2;
} *front2 = 0, *rear2 = 0;

void enqueue2(int b){
    struct node2 *newNode2;
    newNode2 = (struct node2 *)malloc (sizeof(struct node2));
    newNode2->val2 = b;
    newNode2->next2 = NULL;
    if(front2 == 0 && rear2 == 0){
        front2 = newNode2;
        rear2 = newNode2;
    }
    else{
        rear2->next2 = newNode2;
        rear2 = newNode2;
    }
}

void enqueue(int a){
    struct node *newNode;
    newNode = (struct node *)malloc (sizeof(struct node));
    newNode->val = a;
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
    struct node2 *temp2;
    if(front2 == 0 && rear2 == 0){
        printf("Queue is empty..!!");
    }
    else{
        temp2 = front2;
        while(temp2!=0){
            printf("%d  ", temp2->val2);
            temp2 = temp2->next2;
        }
    }
    printf("\n");
}

int main(){
    int y, z;
    printf("Insert node number: ");
    scanf("%d", &y);
    printf("Enter node value: ");
    for(int i = 0; i < y; i++){
        scanf("%d", &z);
        enqueue(z);
    }
    struct node *temp = front;
    while(temp!=NULL){
        if(temp->val >= 0){
            enqueue2(temp->val);
            temp = temp->next;
        }
        else{
            temp = temp->next;
        }
    }
    print_queue();
    return 0;
}










