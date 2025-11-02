#include <stdio.h>
#define INF 9999  // A large number representing infinity
#define MAX 20    // Maximum number of vertices

void primMST(int Graph[MAX][MAX], int n) {
    int selected[MAX];
    int no_of_edges = 0;
    int total_cost = 0;

    // Initialize all vertices as not selected
    for (int i = 0; i < n; i++)
        selected[i] = 0;

    // Start from the first vertex
    selected[0] = 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (no_of_edges < n - 1) {
        int min = INF;
        int x = 0, y = 0;

        // Find the minimum edge from the selected vertices
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && Graph[i][j]) { // Not selected and edge exists
                        if (min > Graph[i][j]) {
                            min = Graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("Edge %d: (%d - %d)  Cost: %d\n", no_of_edges + 1, x, y, Graph[x][y]);
        total_cost += Graph[x][y];
        selected[y] = 1;
        no_of_edges++;
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", total_cost);
}

int main() {
    int Graph[MAX][MAX], n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Graph[i][j]);
            if (Graph[i][j] == 0)
                Graph[i][j] = INF; // Replace 0 with INF for no edge
        }
    }

    primMST(Graph, n);

    return 0;
}
