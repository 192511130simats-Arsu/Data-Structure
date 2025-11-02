#include <stdio.h>

int main() {
    int n, i;
    unsigned long long factorial = 1; // use long long to handle large results

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &n);

    // Check for negative numbers
    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } 
    else {
        // Calculate factorial iteratively
        for (i = 1; i <= n; i++) {
            factorial *= i;
        }

        // Display result
        printf("Factorial of %d = %llu\n", n, factorial);
    }

    return 0;
}
