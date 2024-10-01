#include <stdio.h>
#include <string.h>

struct Weather
{
    char city[100];
    float temperature;
    float humidity;
};

void addWeather(struct Weather weathers[], int *count)
{
    if (*count < 100)
    {
        printf("Enter city: ");
        scanf("%s", weathers[*count].city);
        printf("Enter temperature: ");
        scanf("%f", &weathers[*count].temperature);
        printf("Enter humidity: ");
        scanf("%f", &weathers[*count].humidity);
        (*count)++;
    }
}

void viewWeather(struct Weather weathers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("City: %s\nTemperature: %.2f\nHumidity: %.2f\n", weathers[i].city, weathers[i].temperature, weathers[i].humidity);
    }
}

int main()
{
    struct Weather weathers[100];
    int count = 0;
    int choice;

    while (1)
    {
        printf("1. Add Weather Data\n2. View Weather Data\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addWeather(weathers, &count);
        else if (choice == 2)
            viewWeather(weathers, count);
        else if (choice == 3)
            break;
        else
            printf("Invalid choice. Try again.\n");
    }
    return 0;
}
