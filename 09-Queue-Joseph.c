#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *last = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Enqueue into the circular queue
void enqueue(int data)
{
    struct Node *newNode = createNode(data);
    if (first == NULL)
    {
        first = last = newNode;
        last->next = first; // Circular link
    }
    else
    {
        last->next = newNode;
        last = newNode;
        last->next = first; // Keep it circular
    }
}

// Remove a node after a specific node in the circular queue
void dequeue(struct Node *prevNode)
{
    struct Node *delNode = prevNode->next;
    if (first == last && first == delNode)
    {
        // If there's only one node left
        first = last = NULL;
    }
    else
    {
        if (delNode == first)
        {
            first = first->next;
        }
        if (delNode == last)
        {
            last = prevNode;
        }
        prevNode->next = delNode->next; // Bypass the node to be deleted
    }
    free(delNode); // Free the memory of the deleted node
}

// Josephus function
void josephus(int n, int k)
{
    // Create the circular queue
    for (int i = 1; i <= n; i++)
    {
        enqueue(i);
    }

    struct Node *temp = first;
    while (temp->next != temp)
    {
        // Move `k-1` steps to find the node just before the one to delete
        for (int i = 1; i < k - 1; i++)
        {
            temp = temp->next;
        }
        dequeue(temp);
        temp = temp->next;
    }

    printf("The last person standing is: %d\n", temp->data);
}

int main()
{
    int n, k;

    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    josephus(n, k);

    return 0;
}
