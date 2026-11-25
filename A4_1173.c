#include <stdio.h>

#define MAX 10

int main(void)
{
    int a[MAX][MAX], b[MAX][MAX], rows, cols;
    printf("Enter rows and columns for both matrices (1 to 10 each): ");
    if (scanf("%d%d", &rows, &cols) != 2 || rows < 1 || rows > MAX ||
        cols < 1 || cols > MAX) return 1;

    puts("Enter first matrix row by row:");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (scanf("%d", &a[i][j]) != 1) return 1;

    puts("Enter second matrix row by row:");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (scanf("%d", &b[i][j]) != 1) return 1;

    puts("Addition (A + B):");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%lld ", (long long)a[i][j] + b[i][j]);
        putchar('\n');
    }
    puts("Subtraction (A - B):");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%lld ", (long long)a[i][j] - b[i][j]);
        putchar('\n');
    }
    return 0;
}
