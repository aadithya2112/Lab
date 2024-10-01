#include <stdio.h>

struct Point
{
    int x;
    int y;
};

void initializePoint(struct Point *p)
{
    printf("X cord: ");
    scanf("%d", &p->x);
    printf("Y cord: ");
    scanf("%d", &p->y);
}

void displayPoint(const struct Point *p)
{
    printf("\nPoint Coordinates:\n");
    printf("x: %d\n", p->x);
    printf("y: %d\n", p->y);
}

void modifyPoint(struct Point *p)
{
    printf("New x cord: ");
    scanf("%d", &p->x);
    printf("New y cord: ");
    scanf("%d", &p->y);
}

int main()
{
    struct Point point1;
    int choice;
    initializePoint(&point1);
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. View Point Coordinates\n");
        printf("2. Modify Point Coordinates\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayPoint(&point1);
            break;
        case 2:
            modifyPoint(&point1);
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
