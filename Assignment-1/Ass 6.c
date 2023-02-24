#include <stdio.h>
#include <stdlib.h>

struct stack1{
    int data1;
    struct stack1 *next1;
} *top1 = NULL, *newNode1;
struct stack2{
    int data2;
    struct stack2 *next2;
} *top2 = NULL, *newNode2;
struct queue3{
    int val3;
    struct queue3 *next3;
} *front3 = 0, *rear3 = 0;
struct queue4{
    int val4;
    struct node4 *next4;
} *front4 = 0, *rear4 = 0;
void push1(int a){
    newNode1 = (struct stack1 *)malloc(sizeof(struct stack1));
    newNode1->data1 = a;
    if(top1 == NULL){
        newNode1->next1 = NULL;
        top1 = newNode1;
    }else{
        newNode1->next1 = top1;
        top1 = newNode1;
    }
}
void push2(int b){
    newNode2 = (struct stack2 *)malloc(sizeof(struct stack2));
    newNode2->data2 = b;
    if(top2 == NULL){
        newNode2->next2 = NULL;
        top2 = newNode2;
    }else{
        newNode2->next2 = top2;
        top2 = newNode2;
    }
}
void pop1(){
    struct stack1 *temp1;
    if(top1==NULL){
        printf("Stack is empty");
    }
    if(top1 != NULL){
        temp1 = top1;
        top1 = top1->next1;
        enqueue2(temp1->data1);
        free(temp1);

    }
}
void pop2(){
    struct stack2 *temp2;
    if(top2 != NULL){
        temp2 = top2;
        top2 = top2->next2;
        printf("%d  ", temp2->data2);
        free(temp2);
    }
}
void enqueue1(int c){
    struct queue3 *newNode3;
    newNode3 = (struct queue3 *)malloc (sizeof(struct queue3));
    newNode3->val3 = c;
    newNode3->next3 = NULL;
    if(front3 == 0 && rear3 == 0){
        front3 = newNode3;
        rear3 = newNode3;
    }
    else{
        rear3->next3 = newNode3;
        rear3 = newNode3;
    }
}
void enqueue2(int d){
    struct queue4 *newNode4;
    newNode4 = (struct queue4 *)malloc (sizeof(struct queue4));
    newNode4->val4 = d;
    newNode4->next4 = NULL;
    if(front4 == 0 && rear4 == 0){
        front4 = newNode4;
        rear4 = newNode4;
    }
    else{
        rear4->next4 = newNode4;
        rear4 = newNode4;
    }
}
void dequeue1(){
    struct queue3 *temp3;
    temp3 = front3;
    if(front3 == 0 && rear3 == 0){
    }
    else{
        front3 = front3->next3;
        push2(temp3->val3);
        free(temp3);
    }
}
void dequeue2(){
    struct queue4 *temp4;
    temp4 = front4;
    if(front4 == 0 && rear4 == 0){

    }
    else{
        front4 = front4->next4;
        printf("%d  ", temp4->val4);
        free(temp4);
    }
}
int main(){
    int choice, d = 0, y, c = 0, i;
    for(;;){
        printf("      ==> MENU <==     \n");
        printf("1. Input\n");
        printf("2. Deleted\n");
        printf("3. Print\n");
        printf("-----------------------\n");
        printf("==> Choice number: ");

        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter your value: ");
                scanf("%d", &y);
                push1(y);
                enqueue1(y);
                break;

            case 2:
                printf("Deleted is called....\n");
                dequeue1();
                pop1();
                c++;
                d++;
                break;
            case 3:
                printf("Output queue: ");
                for(i = 0; i < c; i++){
                    dequeue2();
                }
                printf("\n");
                printf("Output stack: ");
                for(i = 0; i < d; i++){
                    pop2();
                }
                printf("\n");
                exit(1);
        }
        printf("\n");
    }
    return 0;
}
