#include <stdio.h>

int main() {
    int arr[100], n;
    int i, j, count;
    int visited[100] = {0}; // Keeps track of counted elements

    // Input array size
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nElements repeated exactly twice:\n");
    int found = 0;

    // Find elements repeated exactly twice
    for (i = 0; i < n; i++) {
        if (visited[i])
            continue;

        count = 1;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // Mark as counted
            }
        }

        if (count == 2) {
            printf("%d\n", arr[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No elements are repeated exactly twice.\n");

    return 0;
}
