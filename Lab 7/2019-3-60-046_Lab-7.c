#include<stdio.h>
#define capacity 100
int size = 1;
int data[capacity], count = 1;

void reHeapDown(int position, int lastPosition){
    int leftChild = position*2, rightChild = (position*2)+1, largest = position;
    if(leftChild <= lastPosition && data[leftChild] > data[largest]){
        largest = leftChild;
    }
    if(rightChild <= lastPosition && data[rightChild] > data[largest]){
        largest = rightChild;
    }
    if(largest != position){
        swap(largest, position);
        reHeapDown(largest, lastPosition);
    }
}

void deleteHeap(){
    if(size > 1){
        printf("Successfully deleted heap..!!\n");
    }
    if(size <= 1){
        printf("Heap tree have no element to deleted...!!\n");
    }
    if(size-1 != 0){
        int d = data[1];
        data[1] = data[count-1];
        count--;
        size--;
        reHeapDown(1, count-1);
    }
}

void swap(int a, int b){
    int temp  = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void reHeapUp(int position){
    int parent;
    if(position > 1){
        parent = position/2;
        if(data[position] > data[parent]){
            swap(position, parent);
            reHeapUp(parent);
            return 0;
        }
    }
}

void createHeap(int a){
    data[count] = a;
    reHeapUp(count);
    count++;
    size++;
}

void printHeap(){
    if(size <= 1){
        printf("Heap have no element..!!\n");
    }
    else{
        for(int i = 1; i < size; i++){
            printf("%d ", data[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, x;
    while(1){
        printf("    =>> MENU <<=    \n");
        printf("1. Create\n");
        printf("2. Print Heap\n");
        printf("3. Deleted Heap\n");
        printf("4. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                createHeap(x);
                printf("Successfully add element...!!\n");
                break;
            case 2:
                printHeap();
                printf("\n");
                break;
            case 3:
                deleteHeap();
                break;
            case 4:
                printf("Thank you...!!\n");
                exit(1);
                break;
        }
    }
}
