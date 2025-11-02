#include <stdio.h>

int main() {
    int arr[100];     // array declaration
    int n, i, pos, value, choice;

    // Input initial array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insertion
                printf("Enter position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                } else {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    for (i = n; i >= pos; i--)
                        arr[i] = arr[i - 1];
                    arr[pos - 1] = value;
                    n++;
                    printf("Element inserted successfully!\n");
                }
                break;

            case 2:
                // Deletion
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    for (i = pos - 1; i < n - 1; i++)
                        arr[i] = arr[i + 1];
                    n--;
                    printf("Element deleted successfully!\n");
                }
                break;

            case 3:
                // Display
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Current Array: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", arr[i]);
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
