#include <stdio.h>
#define MAX 5

struct Queue
{
    int first, last, count, data[MAX];
};

void initializeQueue(struct Queue *q)
{
    q->first = 0;
    q->last = -1;
    q->count = 0;
}

void enqueue(struct Queue *q, int student)
{
    if (q->count == MAX)
    {
        printf("The lift is full. Student cannot enter.\n");
    }
    else
    {
        q->last = (q->last + 1) % MAX;
        q->data[q->last] = student;
        q->count++;
        printf("Student %d entered the lift.\n", student);
    }
}

void dequeue(struct Queue *q)
{
    if (q->count == 0)
    {
        printf("The lift is empty. No student to remove.\n");
    }
    else
    {
        printf("Student %d left the lift.\n", q->data[q->first]);
        q->first = (q->first + 1) % MAX;
        q->count--;
    }
}

void display(struct Queue *q)
{
    if (q->count == 0)
    {
        printf("The lift is empty.\n");
    }
    else
    {
        printf("Students in the lift: ");
        for (int i = 0; i < q->count; i++)
        {
            printf("%d ", q->data[(q->first + i) % MAX]);
        }
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    initializeQueue(&q);
    int choice, student;

    while (1)
    {
        printf("\n1. Add Student\n2. Remove Student\n3. Display Students\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter student ID: ");
            scanf("%d", &student);
            enqueue(&q, student);
        }
        else if (choice == 2)
        {
            dequeue(&q);
        }
        else if (choice == 3)
        {
            display(&q);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
