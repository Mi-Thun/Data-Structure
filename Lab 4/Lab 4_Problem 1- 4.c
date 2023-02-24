#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
} *front = 0, *rear = 0;

int main(){
    int choice, data, y;
    while(1){
        printf("            => MENU <=            \n");
        printf("1. Print Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. CopyQueue\n");
        printf("5. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice between (1-5): ");

        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf(" ==> Display <==\n");
                print_queue();;
                break;
            case 2:
                printf("Insert new value: ");
                scanf("%d", &y);
                enqueue(y);
                printf("Insert completed..!!");
                break;
            case 3:
                dequeue();
                printf("Deleted completed..!!");
                break;
            case 4:
                copy_queue();
                printf("Copy done..!!\nGiven queue: ");
                print_queue();
                printf("Copy queue : ");
                print_1();
                break;
            case 5:
                exit(0);
                break;
        }
        printf("\n");
    }
    return 0;
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

void dequeue(){
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0){
        printf("Queue is empty..!!");
    }
    else{
        front = front->next;
        free(temp);
    }
}

void print_queue(){
    struct node *temp;
    if(front == 0 && rear == 0){
        printf("Queue is empty..!!");
    }
    else{
        temp = front;
        while(temp!=0){
            printf("%d  ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct node1{
    int val1;
    struct node1 *next1;
}*front1 = 0, *rear1 = 0, *newNode1;

void copy_queue(){
    struct node *temp;
    temp = front;
    while(temp!=NULL){
        newNode1 = (struct node1 *)malloc (sizeof(struct node1));
        newNode1->val1 = temp->val;
        newNode1->next1 = NULL;
        if(front1 == 0 && rear1 == 0){
            front1 = newNode1;
            rear1 = newNode1;
        }
        else{
            rear1->next1 = newNode1;
            rear1 = newNode1;
        }
        temp = temp->next;
    }
}

void print_1(){
    struct node1 *temp11;
    temp11 = front1;
    while(temp11!=NULL){
        printf("%d  ", temp11->val1);
        temp11 = temp11->next1;
    }
    printf("\n");
}











