#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICIES 100
#define QUEUE_SIZE 100
//implementing unweighted directed graphs 
//using adjacency matrix

typedef struct Graph{
    int numVertices;
    int adjMatrix[MAX_VERTICIES][MAX_VERTICIES];
}Graph;

typedef struct Queue{
    int items[QUEUE_SIZE];
    int front;
    int rear;
}Queue;

void initQueue(Queue* q){
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue* q){
    return q->front == -1;
}
void enqueue(Queue* q, int value){
    if(q->front == -1){
        q->front = value;
    }
    q->rear++;
    q->items[q->rear] = value;
}
int dequeue(Queue* q){
   int item = q->items[q->front];
   q->front++;
   if(q->front > q->rear){
    q->front = q->rear = -1;
   }
   return item;
}
void initGraph(Graph* g, int vertices){
    g->numVertices = vertices;

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            g->adjMatrix[i][j] = 0;
        }
    }
    
}
//Add a directed edge from src to dest
void addEdge(Graph* g, int src, int dest){
    if(src >= g->numVertices || dest >= g->numVertices){
        printf("invalid vertex");
        return;
    }else{
        g->adjMatrix[src][dest] = 1;
    }
}
void removeEdge(Graph* g, int src, int dest){
    if(src >= g->numVertices || dest >= g->numVertices){
        printf("invalid vertex");
        return;
    }else{
        g->adjMatrix[src][dest] = 0;
    }
}
int hasEdge(Graph* g, int src, int dest){
    if(src >= g->numVertices || dest >= g->numVertices){
        return 0;
    }
    return g->adjMatrix[src][dest];
}
void printGraph(Graph* g){
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for(int i = 0; i < g->numVertices; i++){
        printf("%2d ", i);
    }
    printf("\n");
    
    for(int i = 0; i < g->numVertices; i++){
        printf("%2d ", i);
        for(int j = 0; j < g->numVertices; j++){
            printf("%2d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
// get number of outgoing edges from vertex

int getOutDegree(Graph* g, int vertex){
    int count = 0;
    for(int i = 0; i < g->numVertices; i++){
        if(g->adjMatrix[vertex][i] == 1){
            count++;
        }
    }
    return count;
}
int getInDegree(Graph* g, int vertex){
    int count = 0;
    for(int i = 0; i < g->numVertices; i++){
        if(g->adjMatrix[i][vertex] == 1){
            count++;
        }
    }
    return count;
}
void BFS(Graph* g, int startVertex) {
    // Create visited array
    int visited[MAX_VERTICIES] = {0};  // All false initially
    
    // Create queue
    Queue q;
    initQueue(&q);
    
    // Mark start vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(&q, startVertex);
    
    printf("BFS starting from vertex %d: ", startVertex);
    
    while(!isEmpty(&q)) {
        // Dequeue a vertex
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        
        // Get all adjacent vertices
        for(int i = 0; i < g->numVertices; i++) {
            // If there's an edge and vertex not visited
            if(g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}
int main(){
    Graph g;
    initGraph(&g, 5);
    
    // Create directed edges: 0→1, 0→2, 1→3, 2→3, 3→4
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    
    printGraph(&g);
    
    printf("\nOutdegree of vertex 0: %d\n", getOutDegree(&g, 0));
    printf("Indegree of vertex 3: %d\n", getInDegree(&g, 3));
    
    printf("\nEdge 0→1 exists? %s\n", hasEdge(&g, 0, 1) ? "Yes" : "No");
    printf("Edge 1→0 exists? %s\n", hasEdge(&g, 1, 0) ? "Yes" : "No");
    BFS(&g,0 );
    return 0;
}