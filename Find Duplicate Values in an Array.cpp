#include <stdio.h>

int main() {
    int arr[100], n, i, j;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nDuplicate elements in the array are:\n");

    int found = 0; // Flag to track duplicates
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("%d\n", arr[i]);
                found = 1;
                break; // Avoid printing the same duplicate multiple times
            }
        }
    }

    if (!found)
        printf("No duplicate elements found.\n");

    return 0;
}
