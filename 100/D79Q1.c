/*
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex, weight;
    struct Node* next;
};

// Min Heap Node
struct HeapNode {
    int vertex, dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Create new adjacency node
struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->weight = w;
    temp->next = NULL;
    return temp;
}

// Insert into heap
void push(struct MinHeap* h, int v, int d) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = d;

    while (i > 0 && h->heap[(i - 1) / 2].dist > h->heap[i].dist) {
        struct HeapNode temp = h->heap[i];
        h->heap[i] = h->heap[(i - 1) / 2];
        h->heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Extract min
struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];

    int i = 0;
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
            smallest = left;
        if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            struct HeapNode temp = h->heap[i];
            h->heap[i] = h->heap[smallest];
            h->heap[smallest] = temp;
            i = smallest;
        } else break;
    }
    return root;
}

// Dijkstra Algorithm
void dijkstra(struct Node* adj[], int n, int src) {
    int dist[MAX];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode node = pop(&heap);
        int u = node.vertex;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print distances
    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[MAX] = {NULL};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--; // convert to 0-based

        struct Node* temp = newNode(v, w);
        temp->next = adj[u];
        adj[u] = temp;

        // Undirected graph
        temp = newNode(u, w);
        temp->next = adj[v];
        adj[v] = temp;
    }

    int source;
    scanf("%d", &source);
    source--; // 0-based

    dijkstra(adj, n, source);

    return 0;
}
