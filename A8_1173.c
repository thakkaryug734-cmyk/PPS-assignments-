#include <stdio.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main(void)
{
    int first, second;
    printf("Enter the first number: ");
    if (scanf("%d", &first) != 1) return 1;
    printf("Enter the second number: ");
    if (scanf("%d", &second) != 1) return 1;

    printf("\nBefore swapping: First = %d, Second = %d\n", first, second);
    swap(&first, &second);
    printf("After swapping:  First = %d, Second = %d\n", first, second);
    return 0;
}
