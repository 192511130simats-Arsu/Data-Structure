#include <stdio.h>

int main() {
    int arr[100], n, i, search, found = 0;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("Element %d found at position %d (index %d)\n", search, i + 1, i);
            found = 1;
            // You can remove 'break;' below if you want to find all occurrences
            break;
        }
    }

    if (!found)
        printf("Element %d not found in the array.\n", search);

    return 0;
}
