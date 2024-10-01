#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    int regNo;
    char name[100];
    char grade[5];
    struct Student *next;
} Student;

Student *createStudent(int regNo, const char *name, const char *grade)
{
    Student *s = malloc(sizeof(Student));
    s->regNo = regNo;
    strcpy(s->name, name);
    strcpy(s->grade, grade);
    s->next = NULL;
    return s;
}

void addStudent(Student **head, int regNo, const char *name, const char *grade)
{
    Student *s = createStudent(regNo, name, grade), *temp = *head;
    if (!temp)
    {
        *head = s;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = s;
}

void removeFirstStudent(Student **head)
{
    if (*head)
    {
        Student *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        printf("No students to remove\n");
    }
}

void displayStudents(Student *head)
{
    while (head)
    {
        printf("Reg No: %d, Name: %s, Grade: %s\n", head->regNo, head->name, head->grade);
        head = head->next;
    }
}

int main()
{
    Student *head = NULL;
    int choice, regNo;
    char name[100], grade[5];

    while (1)
    {
        printf("\n1. Add Student\n2. Remove First Student\n3. Display Students\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        if (choice == 4)
            break;

        if (choice == 1)
        {
            printf("Enter regNo, name, grade: ");
            scanf("%d", &regNo);
            getchar(); // Consume newline
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove newline
            fgets(grade, sizeof(grade), stdin);
            grade[strcspn(grade, "\n")] = '\0'; // Remove newline
            addStudent(&head, regNo, name, grade);
        }
        else if (choice == 2)
        {
            removeFirstStudent(&head);
        }
        else if (choice == 3)
        {
            displayStudents(head);
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    while (head)
    {
        Student *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
