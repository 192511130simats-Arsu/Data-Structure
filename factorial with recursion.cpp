#include <stdio.h>

// Function to calculate factorial using recursion
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    unsigned long long result;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check for negative input
    if (num < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } 
    else {
        result = factorial(num);
        printf("Factorial of %d = %llu\n", num, result);
    }

    return 0;
}
