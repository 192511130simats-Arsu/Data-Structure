#include <stdio.h>

int main() {
    int arr[100], n;
    int i, j, count;
    int visited[100] = {0};  // Keeps track of already counted elements

    // Input array size
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nFrequency of repeated numbers:\n");

    for (i = 0; i < n; i++) {
        // Skip if already visited
        if (visited[i])
            continue;

        count = 1;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;  // Mark as counted
            }
        }

        // Print only if number is repeated
        if (count > 1)
            printf("Number %d is repeated %d times\n", arr[i], count);
    }

    return 0;
}
