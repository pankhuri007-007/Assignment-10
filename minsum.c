#include <stdio.h>

int columnSum(int a[100][100], int rows, int col, int i)
{
    if (i == rows)
        return 0;

    return a[i][col] + columnSum(a, rows, col, i + 1);
}

int main()
{
    int a[100][100], rows, cols, i, j;
    int minSum, sum, minCol = 0;

    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &cols);

    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
        printf("Invalid matrix size.");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    minSum = columnSum(a, rows, 0, 0);

    for (j = 1; j < cols; j++) {
        sum = columnSum(a, rows, j, 0);

        if (sum < minSum) {
            minSum = sum;
            minCol = j;
        }
    }

    printf("Column with minimum sum: %d\n", minCol + 1);
    printf("Minimum sum: %d", minSum);

    return 0;
}