#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

// Write a program in C to perform the following operations in Array data structure:
// 1.	Creation
// 2.	Display
// 3.	Linear Search
// 4.	Binary Search
// 5.	Insertion Operation
// 6.	Deletion by a given position
// 7.	Deletion by a given item

void creation(int *arr, int n)
{
    printf("Enter the numbers: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void display(int *arr, int n)
{
    printf("The Eliments of the array are: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int linearSearch(int arr[], int a, int n, int x)
{
    if (a >= n)
        return -1;
    else if (arr[a] == x)
        return a;
    return linearSearch(arr, a + 1, n, x);
}

int binarySearch(int arr[], int beg, int end, int x)
{
    if (end < beg)
        return -1;
    int mid = (beg + end) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        return binarySearch(arr, mid + 1, end, x);
    else
        return binarySearch(arr, beg, mid - 1, x);
}

void insertion(int *arr, int *n, int pos, int x)
{
    if (*n >= MAX_SIZE)
        printf("Array overloaded!!!\n");
    else if (pos >= 0 && pos <= *n)
    {
        for (int i = *n - 1; i >= pos; i--)
            arr[i + 1] = arr[i];
        arr[pos] = x;
        (*n)++;
        arr = (int *)realloc(arr, (*n) * sizeof(int));
    }
    else
        printf("Please enter a valid index!!!\n");
}

void deletionByIndex(int *arr, int *n, int pos)
{
    if (*n == 0)
        printf("Sorry array is already empty!!\n");
    else if (pos >= 0 && pos < *n)
    {
        for (int i = pos; i < *n - 1; i++)
            arr[i] = arr[i + 1];
        (*n)--;
        arr = (int *)realloc(arr, (*n) * sizeof(int));
    }
    else
        printf("Enter a valid index!!");
}
void deletionbyValue(int *arr, int *n, int value)
{
    for (int i = *n - 1; i >= 0; i--)
    {
        if (arr[i] == value)
            deletionByIndex(arr, n, i);
    }
}

int main()
{
    int choice, n = 0;
    int *arr = NULL;
    while (1)
    {
        printf("Enter your choice:\n1. create a array\n2. display array\n3. search a eliment\n4. Insert a new Eliment\n5. Delete an Eliment\n0. Exit\n : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;

        case 1:
            printf("Enter the size of the array: ");
            scanf("%d", &n);
            arr = (int *)malloc(n * sizeof(int));
            creation(arr, n);
            break;

        case 2:
            display(arr, n);
            break;

        case 3:
            int x, resultindex;
            printf("Enter the number to be found: ");
            scanf("%d", &x);
            printf("Is the array is sorted (y/n)? :");
            fflush(stdin);
            char ch = getchar();
            switch (ch)
            {
            case 'y':
                resultindex = binarySearch(arr, 0, n, x);
                break;
            case 'n':
                resultindex = linearSearch(arr, 0, n, x);
                break;
            default:
                printf("Please enter (y/n) format.\n");
                break;
            }
            if (resultindex == -1)
                printf("%d is not present in the array!!\n", x);
            else
                printf("%d is present in the %dth position!!\n", x, resultindex + 1);
            break;

        case 4:
            int pos, data;
            printf("Enter the number to be insert: ");
            scanf("%d", &data);
            printf("Enter the position where to be insert: ");
            scanf("%d", &pos);
            insertion(&arr[0], &n, pos - 1, data);
            break;

        case 5:
            int c;
            printf("1. Deletion with position\n2. Deletion with value\n : ");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                int pos;
                printf("Enter the position from where to be delete: ");
                scanf("%d", &pos);
                deletionByIndex(&arr[0], &n, pos - 1);
                break;
            case 2:
                int data;
                printf("Enter the number to be delete: ");
                scanf("%d", &data);
                deletionbyValue(&arr[0], &n, data);
                break;
            default:
                printf("Enter a valid option!!!");
                break;
            }
            break;

        default:
            printf("Enter a valid option!!!\n");
            break;
        }
    }
    return 0;
}