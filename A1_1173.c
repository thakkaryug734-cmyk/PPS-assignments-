#include <stdio.h>
#include <string.h>

int main(void)
{
    char email[80], password[80];
    puts("Login simulation. Use student@example.com and demo123.");
    while (1) {
        printf("Demo email: ");
        if (scanf("%79s", email) != 1) return 1;
        printf("Demo password: ");
        if (scanf("%79s", password) != 1) return 1;
        if (strcmp(email, "student@example.com") == 0 &&
            strcmp(password, "demo123") == 0) {
            puts("Login successful. Welcome to your demo inbox.");
            break;
        }
        puts("Login error. Try again.");
    }
    return 0;
}
