#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
} *top = NULL, *newNode;

int main(){
    int c = 0, d = 0, y;
    while(1){
        printf("Enter your value: ");
        scanf("%d", &y);
        if(y > 0){
            push(y);
            c++;
            d++;
        }
        if(y < 0){
            if(d>=5){
                display(5);
                pop();c--;
                pop();c--;
                pop();c--;
                pop();c--;
                pop();c--;d = 0;
            }
            else if(d < 5){
                printf("Error \n");
            }
        }
        if(y == 0){
            display(c);
            exit(1);
        }
    }
    return 0;
}

void display(int a){
    int c = a;
    printf("Result: ");
    struct stack *temp = top;
    if(temp==NULL){
        printf("Stack is empty");
    }
    while(temp != NULL & c != 0){
        printf("%d  ", temp -> data);
        temp = temp -> next;
        c--;
    }
    printf("\n");
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
    struct stack *temp;
    if(top==NULL){
        printf("Stack is empty");
    }
    if(top != NULL){
        temp = top;
        top = top->next;
        free(temp);
    }
}










