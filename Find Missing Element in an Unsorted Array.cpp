#include <stdio.h>

int main() {
    int arr[100], n, i;
    int min, max, sum = 0, totalSum, missing;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements (unsorted, consecutive numbers with one missing):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Find minimum and maximum elements
    min = max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    // Expected sum of consecutive numbers from min to max
    totalSum = (max * (max + 1)) / 2 - ((min - 1) * min) / 2;

    missing = totalSum - sum;

    printf("\nMissing element in the array is: %d\n", missing);

    return 0;
}
