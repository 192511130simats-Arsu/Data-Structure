#include <stdio.h>
#define MAX 20  // Maximum number of vertices

int queue[MAX];
int front = -1, rear = -1;

// Function to insert element into queue
void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

// Function to remove element from queue
int dequeue() {
    int vertex;
    if (front == -1 || front > rear)
        return -1;
    vertex = queue[front];
    front++;
    return vertex;
}

// Breadth First Search function
void BFS(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    int i, current;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(adj, visited, start, n);

    return 0;
}
