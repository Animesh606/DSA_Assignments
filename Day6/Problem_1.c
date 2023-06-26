#include <stdio.h>
#include <stdlib.h>

// Write a program in C to perform the following operations in Array data structure:
// 1.	Creation
// 2.	Display
// 3.	Selection Sort
// 4.	Bubble Sort
// 5.	Modified Bubble Sort
// 6.	Insertion Sort
// 7.	Merge Sort

int *creation(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter all data : \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    return arr;
}

void display(int *arr, int size)
{
    if (size)
    {
        printf("Array -> ");
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
        printf("Array is empty!!\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        swap(&arr[i], &arr[minindex]);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void modifiedBubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 0;
            }
        }
        if (flag)
            break;
    }
}

void insertionSort(int *arr, int n)
{
    for (int i = 1, j; i < n; i++)
    {
        int key = arr[i];
        for (j = i - 1; j >= 0 && key < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void merge(int *arr, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0, *arr2 = (int *)malloc((r - l + 1) * sizeof(int));
    while ((i <= mid) && (j <= r))
    {
        if (arr[i] < arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }
    if (i <= mid)
        for (int p = i; p <= mid; p++)
            arr2[k++] = arr[p];
    else
        for (int p = j; p <= r; p++)
            arr2[k++] = arr[p];
    for (int p = l; p <= r; p++)
        arr[p] = arr2[p - l];
}
void mergeSort(int *arr, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    int choice, size = 0, *arr;
    while (1)
    {
        printf("Choose a option:\n1. Creation\n2. Display\n3. Selection Sort\n4. BubbleSort\n5. Modified Bubble Sort\n6. Insertion Sort\n7. Merge Sort\n0. Exit\n :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;

        case 1:
            printf("Enter Number of Data : ");
            scanf("%d", &size);
            arr = creation(size);
            break;

        case 2:
            display(arr, size);
            break;

        case 3:
            selectionSort(arr, size);
            break;

        case 4:
            bubbleSort(arr, size);
            break;

        case 5:
            modifiedBubbleSort(arr, size);
            break;

        case 6:
            insertionSort(arr, size);
            break;

        case 7:
            mergeSort(arr, 0, size - 1);
            break;

        default:
            printf("Enter an valid option!!!\n");
            break;
        }
    }
    return 0;
}