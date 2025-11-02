#include <stdio.h>

int main() {
    int n, i, num;

    // Input: total numbers
    printf("Enter how many numbers you want to check: ");
    scanf("%d", &n);

    // Loop through each number
    for (i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        // Check if number is even or odd
        if (num % 2 == 0)
            printf("%d is Even\n", num);
        else
            printf("%d is Odd\n", num);
    }

    return 0;
}
