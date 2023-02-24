#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert_at_beginning();
void insert_at_end();
void insert_at_any_position();
void delete_at_beginning();
void delete_at_end();
void delete_at_any_position();

struct node{
    int val;
    struct node *next, *prev;
};

struct node *curr, *tail=NULL, *head=NULL;

int main(){
    for(;;){
        printf("\n.............MENU..............\n");
        printf("...............................\n");
        printf("1.  Crate\n");
        printf("2.  Display\n");
        printf("3.  Insert at the beginning\n");
        printf("4.  Insert at the end\n");
        printf("5.  Insert at the any position\n");
        printf("6.  delete at the beginning\n");
        printf("7.  delete at the end\n");
        printf("8.  delete at any position\n");
        printf("7.  Exit\n");
        printf("...............................\n");
        printf("Enter number: ");
        int x;
        scanf("%d", &x);
        switch(x){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_at_beginning();
                break;
            case 4:
                insert_at_end();
                break;
            case 5:
                insert_at_any_position();
                break;
            case 6:
                delete_at_beginning();
                break;
            case 7:
                delete_at_end();
                break;
            case 8:
                delete_at_any_position();
                break;
        }
    }
}

void create(){
    int i, n;
    printf("node number: ");
    scanf("%d", &n);
    printf("value ");
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
void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d  ", temp -> val);
        temp = temp -> next;
    }
}

insert_at_beginning(){
    curr = (struct node *) malloc(sizeof(struct node));
     printf("value ");
     scanf("%d", &curr -> val);
     curr -> next = NULL;
     curr ->prev = NULL;
     if(head == NULL){
            head = curr;
            tail = curr;
    } else{
            struct node *temp;
            temp = head;
            head = curr;
            curr->next = temp;
            temp->prev = curr;
    }
}

insert_at_end(){
    struct node *temp;
     curr = (struct node *) malloc(sizeof(struct node));
     printf("value ");
     scanf("%d", &curr -> val);
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

insert_at_any_position(){
    int posi, i;
     struct node *temp, *temp1;
     curr = (struct node *) malloc(sizeof(struct node));
     printf("where ");
     scanf("%d", &posi);
     printf("value ",posi);
     scanf("%d", &curr -> val);
     curr -> next = NULL;
     curr-> prev = NULL;
     if(head == NULL){
            head = curr;
            tail = curr;
    } else{
        temp = head;
        for(i = 1; i <= posi-1; i++){
            temp1 = temp;
            temp = temp->next;
        }
        temp1 -> next = curr;
        curr -> prev = temp1;
        curr ->next = temp;
        temp->prev = curr;
    }
}

void delete_at_beginning(){
    struct node *temp;
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void delete_at_end(){
    struct node *temp;
    temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}

void delete_at_any_position(){
    int posi, i, c = 0;
    struct node *temp, *temp1, *temp2;
    printf("Enter node position which one you want to remove: ");
    scanf("%d", &posi);
    if(head != NULL){
        temp = head;
        for(i = 1; i <= posi-1; i++){
            temp1 = temp;
            temp = temp->next;
            c++;
        }
        if(c!=0){
            temp2 = temp->next;
            temp1 -> next = temp2;
            temp2->prev = temp1;
            free(temp);
        }
    }
}










