#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;
};

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

  int i;
  for (i = 0; i < vertices; i++) {
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
        printf("\nvertex %d ", v);
    }
    while(temp) {
        printf("--> %d ", temp->vertex);
        temp = temp->next;
      }
    }
    printf("\n");
}

int main() {
    int n, v, e, choice, how;
    struct Graph* graph = createGraph(10);
    while(1){
        printf("1. Create Graph");
        printf("\n2. Display Graph");
        printf("\n3. Add new vertex and edge");
        printf("\n4. Delete vertex");
        printf("\n5. Exit");
        printf("\n---------------------------");
        printf("\nEnter number between 1-6: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("How many: ");
                scanf("%d", &how);
                printf("Enter vertex and edge: ");
                for(int i = 0; i < how; i++){
                    scanf("%d %d", &v, &e);
                    addEdge(graph, e, v);
                }
                break;
            case 2:
                printGraph(graph);
                break;
            case 3:
                printf("Enter vertex and edge: ");
                scanf("%d %d", &v, &e);
                addEdge(graph, e, v);
                break;
            case 4:
                printf("Enter node: ");
                scanf("%d", &choice);

                break;
            case 5:
                exit(1);
        }
        printf("\n");
    }
    return 0;
}
