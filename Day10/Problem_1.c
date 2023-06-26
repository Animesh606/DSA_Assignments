#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Write a program in C to Convert a given infix expression into an equivalent postfix expression.

typedef struct Stack
{
    int top, maxsize;
    char *arr;
} stack;

stack *createStack(int _maxsize)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->maxsize = _maxsize;
    s->arr = (char *)malloc(s->maxsize * sizeof(char));
}

void push(stack *s, char data)
{
    if (s->top == s->maxsize - 1)
        printf("\n!!stack overflow!!\n");
    else
        s->arr[++s->top] = data;
}

char pop(stack *s)
{
    if (s->top == -1)
        printf("\nStack is already empty\n");
    else
        return (s->arr[s->top--]);
}

int priority(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 3;

    case '^':
        return 5;

    default:
        return -1;
    }
}

char *infixToPostfix(char *infix)
{
    stack *s = createStack(50);
    char *postfix = (char *)malloc(50 * sizeof(char));
    int i, j;
    push(s, '(');
    for (i = 0, j = 0; infix[i]; i++)
    {
        char c = infix[i];
        switch (c)
        {
        case '(':
            push(s, c);
            break;

        case ')':
            while (s->arr[s->top] != '(')
                postfix[j++] = pop(s);
            pop(s);
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (priority(c) <= priority(s->arr[s->top]))
                postfix[j++] = pop(s);
            push(s, c);
            break;
        default:
            postfix[j++] = c;
        }
    }
    while (s->arr[s->top] != '(')
        postfix[j++] = pop(s);
    pop(s);
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = (char *)malloc(50 * sizeof(char));
    printf("Enter the Infix Expression: \n");
    scanf("%s", infix);
    char *posfix = infixToPostfix(infix);
    printf("The postfix expression is:\n");
    printf("%s\n", posfix);
    return 0;
}