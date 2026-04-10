/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// Min heap (priority queue)
struct MinHeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct MinHeapNode arr[MAX];
};

// Swap
void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Extract min
struct MinHeapNode extractMin(struct MinHeap* heap) {
    struct MinHeapNode root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapify(heap, 0);
    return root;
}

// Insert into heap
void insertHeap(struct MinHeap* heap, int v, int dist) {
    int i = heap->size++;
    heap->arr[i].vertex = v;
    heap->arr[i].dist = dist;

    while (i && heap->arr[(i-1)/2].dist > heap->arr[i].dist) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dijkstra Algorithm
void dijkstra(struct Graph* graph, int src) {
    int dist[MAX];

    for (int i = 0; i < graph->V; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    insertHeap(&heap, src, 0);

    while (heap.size > 0) {
        struct MinHeapNode minNode = extractMin(&heap);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < graph->V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Driver code
int main() {
    struct Graph graph;
    graph.V = 5;

    for (int i = 0; i < graph.V; i++)
        graph.adj[i] = NULL;

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 4, 5);
    addEdge(&graph, 1, 2, 1);
    addEdge(&graph, 4, 1, 3);
    addEdge(&graph, 4, 2, 9);
    addEdge(&graph, 4, 3, 2);
    addEdge(&graph, 2, 3, 4);
    addEdge(&graph, 3, 2, 6);

    dijkstra(&graph, 0);

    return 0;
}