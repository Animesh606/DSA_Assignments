#include <stdio.h>
#include <stdlib.h>
// Write a program in C to implement the following on stack
// 1. push
// 2. pop
// 3. Display

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

void pop(stack *s)
{
    if (s->top == -1)
        printf("\nStack is already empty\n");
    else
        s->top--;
}

void display(stack *s)
{
    if(s->top == -1)
        printf("Stack is empty!!\n");
    else
    {
        printf("The Stack is :\n    Top\t -> %d\n", s->arr[s->top]);
        for (int i = s->top - 1; i >= 0; i--)
            printf("\t -> %d\n", s->arr[i]);
        printf("\n");
    }
}

int main()
{
    int size, maxsize = 30, value, co;
    stack *s = createStack(maxsize);
    while (1)
    {
        printf("Choose option:\n1. Push\n2. Pop\n3. Display\n0. Exit\n : ");
        scanf("%d", &co);
        switch (co)
        {
        case 1:
            int data;
            printf("Enter a data to push: ");
            scanf("%d", &data);
            push(s, data);
            break;

        case 2:
            pop(s);
            break;

        case 3:
            display(s);
            break;

        case 0:
            exit(0);
            break;
        default:
            printf("Please enter a valid option!!\n");
            break;
        }
    }

    return 0;
}