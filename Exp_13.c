#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph structure using an adjacency matrix
struct Graph {
    int V; // Number of vertices
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Initialize a graph with V vertices
void initGraph(struct Graph* G, int V) {
    G->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            G->adjMatrix[i][j] = false;
        }
    }
}

// Add an edge to the graph
void addEdge(struct Graph* G, int src, int dest) {
    if (src >= 0 && src < G->V && dest >= 0 && dest < G->V) {
        G->adjMatrix[src][dest] = true;
        G->adjMatrix[dest][src] = true; // For an undirected graph
    } else {
        printf("Invalid vertex.\n");
    }
}

// Print the adjacency matrix of the graph
void printGraph(struct Graph* G) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < G->V; i++) {
        for (int j = 0; j < G->V; j++) {
            printf("%d ", G->adjMatrix[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    int V = 5; // Number of vertices

    initGraph(&graph, V);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 4);

    printGraph(&graph);

    return 0;
}
