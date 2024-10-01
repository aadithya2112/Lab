#include <stdio.h>
#include <stdlib.h>

// Node structure for each student in the queue
struct Node
{
    int studentID;
    struct Node *next;
};

// Queue structure with pointers to first and last nodes
struct Queue
{
    struct Node *first;
    struct Node *last;
};

// Function to initialize the queue
void initializeQueue(struct Queue *q)
{
    q->first = NULL;
    q->last = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->first == NULL;
}

// Function to add a student to the queue
void enqueue(struct Queue *q, int studentID)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->studentID = studentID;
    newNode->next = NULL;

    if (q->last != NULL)
    {
        q->last->next = newNode;
    }
    q->last = newNode;

    if (q->first == NULL)
    {
        q->first = newNode;
    }

    printf("Student %d entered the lift.\n", studentID);
}

// Function to remove a student from the queue
void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("The lift is empty. No student to remove.\n");
    }
    else
    {
        struct Node *temp = q->first;
        printf("Student %d left the lift.\n", temp->studentID);
        q->first = q->first->next;

        if (q->first == NULL)
        {
            q->last = NULL;
        }

        free(temp);
    }
}

// Function to display the students in the queue
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("The lift is empty.\n");
    }
    else
    {
        struct Node *temp = q->first;
        printf("Students in the lift: ");
        while (temp != NULL)
        {
            printf("%d ", temp->studentID);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    initializeQueue(&q);
    int choice, studentID;

    while (1)
    {
        printf("\n1. Add Student\n2. Remove Student\n3. Display Students\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter student ID: ");
            scanf("%d", &studentID);
            enqueue(&q, studentID);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
