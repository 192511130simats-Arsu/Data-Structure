#include <stdio.h>

int main() {
    int arr[10][10];
    int row, col, i, j;
    int rowSum, colSum;

    // Input matrix size
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Display the matrix
    printf("\nMatrix entered:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    // Calculate sum of each row
    printf("\nSum of each row:\n");
    for (i = 0; i < row; i++) {
        rowSum = 0;
        for (j = 0; j < col; j++) {
            rowSum += arr[i][j];
        }
        printf("Row %d = %d\n", i + 1, rowSum);
    }

    // Calculate sum of each column
    printf("\nSum of each column:\n");
    for (j = 0; j < col; j++) {
        colSum = 0;
        for (i = 0; i < row; i++) {
            colSum += arr[i][j];
        }
        printf("Column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
