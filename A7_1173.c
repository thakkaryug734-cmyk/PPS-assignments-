#include <stdio.h>

struct Student {
    int roll;
    char name[80];
    int marks[3];
    int total;
};

int main(void)
{
    struct Student students[100];
    int count;
    printf("Enter number of students (1-100): ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 100) {
        puts("Invalid student count.");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d roll number: ", i + 1);
        if (scanf("%d", &students[i].roll) != 1) return 1;
        printf("Name: ");
        if (scanf(" %79[^\n]", students[i].name) != 1) return 1;
        printf("Enter marks for three subjects (out of 100 each): ");
        students[i].total = 0;
        for (int j = 0; j < 3; j++) {
            if (scanf("%d", &students[i].marks[j]) != 1 ||
                students[i].marks[j] < 0 || students[i].marks[j] > 100) {
                puts("Invalid marks.");
                return 1;
            }
            students[i].total += students[i].marks[j];
        }
    }
    printf("\n%-8s %-20s %9s %9s %9s %6s %11s\n",
           "Roll No", "Name", "Subject 1", "Subject 2", "Subject 3", "Total", "Percentage");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %9d %9d %9d %6d %10.2f%%\n",
               students[i].roll, students[i].name, students[i].marks[0],
               students[i].marks[1], students[i].marks[2], students[i].total,
               students[i].total / 3.0);
    }
    return 0;
}
