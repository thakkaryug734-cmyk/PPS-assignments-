#include <stdio.h>

int main(void)
{
    for (;;) {
        int choice;
        double a, b;
        puts("1. Add  2. Subtract  3. Multiply  4. Divide  0. Exit");
        if (scanf("%d", &choice) != 1) return 1;
        if (choice == 0) return 0;
        if (choice < 1 || choice > 4) {
            puts("Invalid choice.");
            continue;
        }
        printf("Enter two numbers: ");
        if (scanf("%lf%lf", &a, &b) != 2) return 1;
        switch (choice) {
        case 1: printf("Addition = %g\n", a + b); break;
        case 2: printf("Subtraction = %g\n", a - b); break;
        case 3: printf("Multiplication = %g\n", a * b); break;
        case 4:
            if (b == 0) puts("Division by zero is undefined.");
            else printf("Division = %g\n", a / b);
            break;
        }
    }
}
