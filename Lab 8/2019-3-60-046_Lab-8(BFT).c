#include <stdio.h>
#include <stdlib.h>
#define MAX 40

struct queue {
    int items[MAX], front, rear;
};

struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int numVertices, *visited;
    struct node **adjLists;
};

struct queue *createQueue() {
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct queue *q, int value) {
    if (q->rear == MAX - 1){
        printf("\nQueue is Full!!");
    }
    else {
        if (q->front == -1){
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int isEmpty(struct queue *q) {
    if(q->rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int dequeue(struct queue *q) {
    int item;
    if(isEmpty(q)) {
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    int i = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty");
    }
    else{
        printf("Queue have ");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
    }
}

void BFT(struct Graph* graph, int startVertex) {
    struct queue *q = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!isEmpty(q)) {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);
        struct node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++){
        struct node* temp = graph->adjLists[v];
        if(temp!=NULL){
            printf("\nvertex %d : ", v);
        }
        while(temp) {
            printf("--> %d ", temp->vertex);
            temp = temp->next;
        }
    }
    printf("\n\n");
}

int main() {
    struct Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 5);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 5, 4);
    addEdge(graph, 3, 4);
    printGraph(graph);
    printf("BFT(Start from 0)==>\n");
    BFT(graph, 0);
    return 0;
}
