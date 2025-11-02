#include <stdio.h>

int main() {
    int arr[100], n;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n >= 5)
        printf("\nThe 5th element (5th iterated element) is: %d\n", arr[4]);
    else
        printf("\nArray has less than 5 elements! Cannot display the 5th element.\n");

    return 0;
}
