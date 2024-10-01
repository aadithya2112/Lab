#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char **tasks;
    int size;
    int capacity;
} TodoList;

void initTodoList(TodoList *list, int capacity)
{
    list->tasks = (char **)malloc(capacity * sizeof(char *));
    list->size = 0;
    list->capacity = capacity;
}

void resizeTodoList(TodoList *list)
{
    int new_capacity = list->capacity * 2;
    char **new_tasks = (char **)malloc(new_capacity * sizeof(char *));
    if (new_tasks == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < list->size; i++)
    {
        new_tasks[i] = list->tasks[i];
    }
    free(list->tasks);
    list->tasks = new_tasks;
    list->capacity = new_capacity;
}

void addTask(TodoList *list, const char *task)
{
    if (list->size == list->capacity)
    {
        resizeTodoList(list);
    }
    list->tasks[list->size] = strdup(task);
    list->size++;
}

void removeTask(TodoList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        printf("Index out of bounds\n");
        return;
    }
    free(list->tasks[index]);
    for (int i = index; i < list->size - 1; i++)
    {
        list->tasks[i] = list->tasks[i + 1];
    }
    list->size--;
}

void printTodoList(TodoList *list)
{
    printf("Todo List:\n");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d: %s\n", i + 1, list->tasks[i]);
    }
}

void freeTodoList(TodoList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        free(list->tasks[i]);
    }
    free(list->tasks);
}

void showMenu()
{
    printf("\nMenu:\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. View Tasks\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    TodoList list;
    initTodoList(&list, 10);

    int choice;
    char task[100];
    int taskIndex;

    while (1)
    {
        showMenu();
        scanf("%d", &choice);
        getchar(); // to consume the newline character left by scanf

        switch (choice)
        {
        case 1:
            printf("Enter the task: ");
            fgets(task, sizeof(task), stdin);
            task[strcspn(task, "\n")] = 0; // Remove the newline character
            addTask(&list, task);
            break;
        case 2:
            printf("Enter the task number to remove: ");
            scanf("%d", &taskIndex);
            getchar(); // to consume the newline character left by scanf
            removeTask(&list, taskIndex - 1);
            break;
        case 3:
            printTodoList(&list);
            break;
        case 4:
            freeTodoList(&list);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

//  *Algorithm for CLI To-Do List Application*
// Step 1: Start
// Step 2: Initialization:
// Step 2.1: Define TodoList structure with fields: char **tasks, int size, int capacity.
// Step 2.2: Implement initTodoList(TodoList *list, int capacity) to initialize the list.
// Step 3: Memory Management:
// Step 3.1: Implement resizeTodoList(TodoList *list) to double the list capacity when needed.
// Step 3.2: Implement freeTodoList(TodoList *list) to free allocated memory.
// Step 4: Task Management:
// Step 4.1: Implement addTask(TodoList *list, const char *task) to add a new task.
// Step 4.2: Implement removeTask(TodoList *list, int index) to remove a task by index.
// Step 5: User Interface:
// Step 5.1: Implement printTodoList(TodoList *list) to display tasks.
// Step 5.2: Implement showMenu() to display menu options.
// Step 6: Main Loop:
// Step 6.1: Initialize TodoList with a capacity of 10 using initTodoList.
// Step 6.2: Enter an infinite loop to display menu and process user input
// Step 7: End