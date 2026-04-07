/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function to detect cycle
bool dfs(int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = false; // remove from recursion stack
    return false;
}

// Function to check cycle
bool isCycle(int V) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return true;
        }
    }
    return false;
}

// Driver code
int main() {
    int V = 4;

    // Initialize adjacency list
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Graph edges (example with cycle)
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 1); // cycle here

    if (isCycle(V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}