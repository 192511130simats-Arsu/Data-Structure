#include <stdio.h>

#define MAX 30

// Structure to represent an edge
typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

// Function to find the parent of a vertex (with path compression)
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Function to perform union of two sets
int unionSet(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskalMST(int n, int cost[MAX][MAX]) {
    Edge edges[MAX];
    int i, j, k = 0;
    int total_cost = 0;
    int ne = 1; // Edge counter

    // Store all edges from adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] != 9999) {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].w = cost[i][j];
                k++;
            }
        }
    }

    // Sort edges by weight (Bubble sort)
    for (i = 0; i < k - 1; i++) {
        for (j = 0; j < k - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = 0;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    i = 0; // Index for edges
    while (ne < n && i < k) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int a = find(u);
        int b = find(v);

        if (unionSet(a, b)) {
            printf("Edge %d: (%d - %d)  Cost: %d\n", ne, u, v, w);
            total_cost += w;
            ne++;
        }
        i++;
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", total_cost);
}

int main() {
    int cost[MAX][MAX];
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 9999; // Replace 0 with infinity
        }
    }

    kruskalMST(n, cost);

    return 0;
}
