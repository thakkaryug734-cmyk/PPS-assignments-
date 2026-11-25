#include <stdio.h>

/* Start with the first number and update the largest after each comparison. */
int main(void)
{
    double first, second, third;
    printf("Enter three numbers: ");
    if (scanf("%lf%lf%lf", &first, &second, &third) != 3) return 1;

    double largest = first;
    if (second > largest) largest = second;
    if (third > largest) largest = third;
    printf("Largest number = %g\n", largest);
    return 0;
}
