#include <stdio.h>
#include <string.h>

struct Flashcard
{
    char question[100];
    char answer[100];
};

void addFlashcard(struct Flashcard *flashcards[], int *count)
{
    if (*count < 100)
    {
        struct Flashcard *fc = flashcards[*count];
        printf("Enter the question: ");
        getchar(); // Consume the newline character left by the previous input
        fgets(fc->question, 100, stdin);
        printf("Enter the answer: ");
        fgets(fc->answer, 100, stdin);

        (*count)++;
    }
    else
    {
        printf("Flashcard limit reached.\n");
    }
}

void viewFlashcards(struct Flashcard *flashcards[], int count)
{
    for (int i = 0; i < count; i++)
    {
        struct Flashcard *fc = flashcards[i];
        printf("Flashcard %d:\n", i + 1);
        printf("Question: %s\n", fc->question);
        printf("Answer: %s\n", fc->answer);
    }
}

int main()
{
    struct Flashcard flashcards[100];
    struct Flashcard *flashcardPointers[100];
    int count = 0, choice;

    for (int i = 0; i < 100; i++)
    {
        flashcardPointers[i] = &flashcards[i];
    }

    while (1)
    {
        printf("1. Add Flashcard\n2. View Flashcards\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addFlashcard(flashcardPointers, &count);
            break;
        case 2:
            viewFlashcards(flashcardPointers, count);
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}