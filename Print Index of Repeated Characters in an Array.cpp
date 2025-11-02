#include <stdio.h>
#include <string.h>

int main() {
    char arr[100];
    int i, j, len;
    int found = 0;

    // Input the array (string)
    printf("Enter a string or array of characters: ");
    gets(arr);  // For safer input, you can use fgets(arr, sizeof(arr), stdin)

    len = strlen(arr);

    printf("\nRepeated characters and their indices:\n");

    // Compare each character with others
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                printf("Character '%c' is repeated at indices %d and %d\n", arr[i], i, j);
                found = 1;
                break; // Avoid multiple reports for the same character
            }
        }
    }

    if (!found)
        printf("No repeated characters found.\n");

    return 0;
}
