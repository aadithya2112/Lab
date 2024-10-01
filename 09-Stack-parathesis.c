#include <stdio.h>

int isValid(char *s)
{
    // create a stack array
    // (())
    //
    char stack[100];
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack[++top] = s[i];
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (top == -1)
                return 0;
            if (s[i] == ')' && stack[top] == '(')
                top--;
            else if (s[i] == '}' && stack[top] == '{')
                top--;
            else if (s[i] == ']' && stack[top] == '[')
                top--;
            else
                return 0;
        }
    }
    return top == -1;
}

int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    if (isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");
    return 0;
}