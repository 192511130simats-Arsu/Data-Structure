#include <stdio.h>
#define INF 9999  // Infinity value for unreachable vertices
#define MAX 20    // Maximum number of vertices

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX];    // Cost matrix
    int distance[MAX];     // Shortest distance from start
    int visited[MAX];      // Track visited vertices
    int count, mindistance, nextnode, i, j;

    // Create the cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = Graph[i][j];

    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    // Main Dijkstra’s Algorithm
    while (count < n - 1) {
        mindistance = INF;

        // Next node with the smallest distance
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        // Check for a shorter path through nextnode
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                    distance[i] = mindistance + cost[nextnode][i];

        count++;
    }

    // Print the shortest distances
    printf("\nShortest distances from vertex %d:\n", start);
    for (i = 0; i < n; i++)
        if (i != start)
            printf("To vertex %d = %d\n", i, distance[i]);
}

int main() {
    int Graph[MAX][MAX], n, start, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &Graph[i][j]);

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    Dijkstra(Graph, n, start);

    return 0;
}
