#include <stdio.h>

int main() {
    int matrix[10][10];
    int rows, cols;
    int i, j, largest;

    // Input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Assume first element is the largest
    largest = matrix[0][0];

    // Traverse matrix to find the largest element
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] > largest) {
                largest = matrix[i][j];
            }
        }
    }

    // Output result
    printf("\nThe largest element in the given 2D matrix is: %d\n", largest);

    return 0;
}
