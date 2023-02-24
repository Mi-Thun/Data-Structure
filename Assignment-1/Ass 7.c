#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
};

struct stack{
    int data;
    struct stack *next;
} *top = NULL, *newNode;

struct node *front = 0, *rear = 0;

int main(){
    int x, y, i, k, c;
    printf("Enter node number: ");
    scanf("%d", &x);
    printf("Input value: ");
    for(i = 0; i < x; i++){
        scanf("%d", &y);
        enqueue(y);
    }
    printf("Enter value of K: ");
    scanf("%d", &k);
    for(i = 0; i < k; i++){
        push(dequeue());
        c++;
    }
    for(i = 0; i < k; i++){
        enqueue(pop());
    }
    printf("Output: ");
    print_queue();
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

int dequeue(){
    struct node *temp;
    int z;
    temp = front;
    if(front == 0 && rear == 0){

    }
    else{
        front = front->next;
        z = temp->val;
        free(temp);
        return z;
    }
}

void print_queue(){
    struct node *temp;
    if(front == 0 && rear == 0){

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

void push(int a){
    newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = a;
    if(top == NULL){
        newNode->next = NULL;
        top = newNode;
    }else{
        newNode->next = top;
        top = newNode;
    }
}

int pop(){
    int k;
    struct stack *temp;
    if(top==NULL){
        printf("Stack is empty");
    }
    if(top != NULL){
        temp = top;
        top = top->next;
        k = temp->data;
        free(temp);
        return k;
    }
}

void display(){
    printf("Result: ");
    struct stack *temp = top;
    if(temp==NULL){
        printf("Stack is empty");
    }
    while(temp != NULL){
        printf("%d  ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}








