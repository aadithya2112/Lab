#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WebPage
{
    char url[50];
    struct WebPage *next;
} *top = NULL;

void pushPage(char url[])
{
    struct WebPage *newPage = (struct WebPage *)malloc(sizeof(struct WebPage));
    strcpy(newPage->url, url);
    newPage->next = top;
    top = newPage;
}

void popPage()
{
    if (top)
    {
        struct WebPage *temp = top;
        printf("Popped: %s\n", top->url);
        top = top->next;
        free(temp);
    }
}

void displayHistory()
{
    for (struct WebPage *temp = top; temp; temp = temp->next)
        printf("%s\n", temp->url);
}

int main()
{
    int choice;
    char url[50];

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

    while (top)
        popPage();

    return 0;
}