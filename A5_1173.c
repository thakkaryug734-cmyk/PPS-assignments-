#include <stdio.h>
#include <string.h>
#include <ctype.h>

int readLine(char s[128])
{
    if (fgets(s, 128, stdin) == NULL)
        return 0;

    int i = strcspn(s, "\n");
    if (s[i] == '\n') {
        s[i] = '\0';
    } else {
        int ch = getchar();
        if (ch != '\n' && ch != EOF) {
            puts("Maximum length is 127 characters.");
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    char menu[128], first[128], second[128], result[256];
    char *match;
    int choice, order, i;

    while (1) {
        puts("1. Length   2. Copy      3. Join       4. Compare");
        puts("5. Find     6. Reverse   7. Uppercase  8. Lowercase");
        puts("0. Exit");
        printf("Enter choice: ");

        if (!readLine(menu))
            break;

        if (strlen(menu) != 1 || menu[0] < '0' || menu[0] > '8') {
            puts("Invalid choice.");
            continue;
        }

        choice = menu[0] - '0';
        if (choice == 0)
            break;

        printf("Enter a string: ");
        if (!readLine(first))
            break;

        if (choice >= 3 && choice <= 5) {
            printf("Enter second string: ");
            if (!readLine(second))
                break;
        }

        switch (choice) {
            case 1:
                printf("Length = %zu\n", strlen(first));
                break;

            case 2:
                strcpy(result, first);
                puts(result);
                break;

            case 3:
                strcpy(result, first);
                strcat(result, second);
                puts(result);
                break;

            case 4:
                order = strcmp(first, second);
                if (order == 0)
                    puts("Strings are equal.");
                else if (order < 0)
                    puts("First string comes before the second.");
                else
                    puts("First string comes after the second.");
                break;

            case 5:
                match = strstr(first, second);
                if (match != NULL)
                    printf("Found at index %td\n", match - first);
                else
                    puts("Substring not found.");
                break;

            case 6:
                for (i = (int)strlen(first) - 1; i >= 0; i--)
                    putchar(first[i]);
                putchar('\n');
                break;

            case 7:
                for (i = 0; first[i] != '\0'; i++)
                    putchar(toupper((unsigned char)first[i]));
                putchar('\n');
                break;

            case 8:
                for (i = 0; first[i] != '\0'; i++)
                    putchar(tolower((unsigned char)first[i]));
                putchar('\n');
                break;
        }
    }

    return 0;
}
