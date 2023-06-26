#include <stdio.h>
#include <stdlib.h>

// Problem 3:
// Write a program in C language to store all elements in an array and display them and search the position of a given item in functional way.

int *createarray(int n)
{
    int *arr = (int *)calloc(n, sizeof(int));
    printf("Enter the %d eliments: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return arr;
}

void display(int *arr, int n)
{
    if (arr)
    {
        printf("The Elements : ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
        printf("NO element found!!\n");
}

int linearsearch(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int chooseoption, n, x, result, *arr = NULL;
    while (1)
    {
        printf("Enter your choice :\n1. Create an array\n2. Display\n3. Search an element\n0. Exit\n : ");
        scanf("%d", &chooseoption);
        switch (chooseoption)
        {
        case 1:
            printf("Enter the size of Array : ");
            scanf("%d", &n);
            arr = createarray(n);
            break;

        case 2:
            display(arr, n);
            break;

        case 3:
            printf("Enter the number to be find: ");
            scanf("%d", &x);
            result = linearsearch(arr, n, x) + 1;
            if (result)
                printf("%d is present on the %dth position!!\n", x, result);
            else
                printf("%d is not present in the list!!!\n", x);
            break;

        case 0:
            exit(0);
            break;

        default:
            printf("Enter an valid option!!\n");
            break;
        }
    }

    return 0;
}