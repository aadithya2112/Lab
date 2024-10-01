#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

char **webHistoryArr;
int top = -1;
int capacity = SIZE;

void pushPage(char url[])
{
    if (++top >= capacity)
    {
        capacity *= 2;
        webHistoryArr = realloc(webHistoryArr, capacity * sizeof(char *));
    }
    webHistoryArr[top] = strdup(url);
}

void popPage()
{
    if (top >= 0)
    {
        printf("Popped: %s\n", webHistoryArr[top--]);
        free(webHistoryArr[top + 1]);
    }
}

void displayHistory()
{
    for (int i = 0; i <= top; i++)
        printf("%s\n", webHistoryArr[i]);
}

int main()
{
    int choice;
    char url[50];
    webHistoryArr = (char **)malloc(capacity * sizeof(char *));

    while (1)
    {
        printf("1. Visit Page\n2. Back\n3. Show History\n4. Exit\n");
        scanf("%d", &choice);
        if (choice == 4)
            break;

        if (choice == 1)
        {
            printf("Enter URL: ");
            scanf("%s", url);
            pushPage(url);
        }
        else if (choice == 2)
        {
            popPage();
        }
        else if (choice == 3)
        {
            displayHistory();
        }
    }

    for (int i = 0; i <= top; i++)
        free(webHistoryArr[i]);
    free(webHistoryArr);

    return 0;
}