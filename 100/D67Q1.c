/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
};

// Stack
int stack[MAX];
int top = -1;

// Push to stack
void push(int value) {
    stack[++top] = value;
}

// DFS function
void dfs(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];

    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    push(vertex);
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Topological sort
void topologicalSort(struct Graph* graph) {
    int visited[MAX] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Driver code
int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}