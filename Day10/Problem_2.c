#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Write a program to implement the postfix evaluation algorithm

typedef struct Stack
{
    int top, maxsize, *arr;
} stack;

stack *createStack(int _maxsize)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->maxsize = _maxsize;
    s->arr = (int *)malloc(s->maxsize * sizeof(int));
}

void push(stack *s, int data)
{
    if (s->top == s->maxsize - 1)
        printf("\n!!stack overflow!!\n");
    else
        s->arr[++s->top] = data;
}

int pop(stack *s)
{
    if (s->top == -1)
        printf("\nStack is already empty\n");
    else
        return s->arr[s->top--];
}

void display(stack *s)
{
    printf("The Stack is :\n    Top\t -> %d\n", s->arr[s->top]);
    for (int i = s->top - 1; i >= 0; i--)
        printf("\t -> %d\n", s->arr[i]);
    printf("\n");
}

int evalute(char *postfix)
{
    stack *s = createStack(30);
    int i = 0;
    while (postfix[i])
    {
        char c = postfix[i++];
        int x, y;
        switch (c)
        {
        case '+':
            y = pop(s);
            x = pop(s);
            push(s, x + y);
            break;

        case '-':
            y = pop(s);
            x = pop(s);
            push(s, x - y);
            break;

        case '*':
            y = pop(s);
            x = pop(s);
            push(s, x * y);
            break;

        case '/':
            y = pop(s);
            x = pop(s);
            push(s, x / y);
            break;

        case '^':
            y = pop(s);
            x = pop(s);
            push(s, pow(x, y));
            break;

        default:
            push(s, c - '0');
            break;
        }
    }
    return pop(s);
}

int main()
{
    char *postfix = (char *)malloc(30 * sizeof(char));
    printf("Enter the postfix Expression: \n");
    scanf("%s", postfix);
    printf("The value of the expression is %d\n", evalute(postfix));
    return 0;
}