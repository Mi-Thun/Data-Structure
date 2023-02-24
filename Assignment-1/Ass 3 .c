#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next, *prev;
} * head = NULL, *tail = NULL, *curr;

void create(int n){
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

void display(){
    struct node *temp = head;
    while (temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void swap(struct node *x, struct node *y) {
	struct node *node2, *node4, *node1, *temp, *t = NULL;
	node2 = y->next;
	node2->prev = y;
	node2->next = x;
	node4 = x->next;
	node4->next = x;
	temp = x;
	y->next = node4;
	node4->prev = y;
	if(y->prev != NULL){
        node1 = y->prev;
        y->prev = node2;
        node2->next = y;
	}
	else{
        t = head;
        y->prev = node2;
        node2->next = y;
	}
	temp->next = node2;
	node2->prev = temp;
	if(t == NULL){
        temp->prev = node1;
        node1->next = temp;
	}
	else{
        temp->prev = NULL;
        head = temp;
	}
}

void find_node(int a, int b){
    int i;
    struct node *temp1, *temp2;
    temp1 = head;
    for(i = 1; i < a; i++){
        temp1 = temp1->next;
    }
    temp2 = head;
    for(i = 1; i <= b; i++){
        temp2 = temp2->next;
    }
    swap(temp1, temp2);
}


int main(){
    int n, s;
    printf("Enter number of node to create: ");
    scanf("%d", &n);
    printf("Enter node value: ");
    create(n);
    s = n;
    while(s > 2){
        if(s%2 != 0){
            s = (s+1)/2;
            if(s > 2){
                find_node(s, s-2);
            }
            else
                break;
        }
        else{
            s = s / 2;
            if(s > 2){
                find_node(s, s-2);
            }
            else
                break;
        }
    }
    printf("Result Is: \n");
    display();
    return 0;
}
