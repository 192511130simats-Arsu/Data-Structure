#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char temp;
    int i, j;

    // Input string
    printf("Enter a string: ");
    gets(str);  // (For safety, you can use fgets instead of gets in modern compilers)

    int len = strlen(str);

    // Sort characters using simple bubble sort
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("\nString after sorting in alphabetical order: %s\n", str);

    return 0;
}
