#include <stdio.h>

unsigned long long factorial_loop(int n)
{
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

unsigned long long factorial_recursive(int n)
{
    if (n <= 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

int main(void)
{
    int n;
    printf("Enter an integer from 0 to 20: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        puts("Invalid input.");
        return 1;
    }
    printf("Without recursion: %llu\n", factorial_loop(n));
    printf("With recursion: %llu\n", factorial_recursive(n));
    return 0;
}
