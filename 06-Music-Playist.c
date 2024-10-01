#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char song[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(char *song)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->song, song);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addSong(struct Node **head, char *song)
{
    struct Node *newNode = createNode(song);
    struct Node *temp = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void displayPlaylist(struct Node *head)
{
    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }
    printf("Playlist:\n");
    while (head != NULL)
    {
        printf("%s\n", head->song);
        head = head->next;
    }
}

void deleteSong(struct Node **head, char *song)
{
    struct Node *temp = *head;

    while (temp != NULL && strcmp(temp->song, song) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Song not found.\n");
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Song deleted.\n");
}

int main()
{
    struct Node *playlist = NULL;
    int choice;
    char song[100];

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Delete Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter song name: ");
            scanf(" %[^\n]s", song);
            addSong(&playlist, song);
            break;
        case 2:
            displayPlaylist(playlist);
            break;
        case 3:
            printf("Enter song name to delete: ");
            scanf(" %[^\n]s", song);
            deleteSong(&playlist, song);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}