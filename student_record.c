#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int roll;
    float marks;
};

void addStudent() {
    struct student s;
    FILE *fp = fopen("students.txt", "a");

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student record added.\n");
}

void viewStudents() {
    struct student s;
    FILE *fp = fopen("students.txt", "r");

    printf("\nAll Student Records:\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Name: %s | Roll: %d | Marks: %.2f\n", s.name, s.roll, s.marks);
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\n1. Add Student\n2. View Students\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}
