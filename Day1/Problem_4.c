#include <stdio.h>

// Problem 4:
// Write a program in C language to take a String as an input having length n (dynamically) and generate all possible strings from the n symbols of your given string and display the total number of strings.

// Example:
// Input: n=3
// String: ABC
// Output::
// ABC
// ACB
// BAC
// BCA
// CAB
// CBA
// TOTAL NUMBER OF STRINGS: 6

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void printArrangements(char *arr, int a, int n, int *arrangecount)
{
    if (a == n)
    {
        printf("%s\n", arr);
        (*arrangecount)++;
    }
    else
    {
        for (int i = a; i <= n; i++)
        {
            if (*(arr + a) != *(arr + i))
            {
                swap(arr + a, arr + i);
                printArrangements(arr, a + 1, n, arrangecount);
                swap(arr + a, arr + i);
            }
            else
                printArrangements(arr, a + 1, n, arrangecount);
        }
    }
}
int main()
{
    int n, arrangecount = 0;
    printf("Enter size of string : ");
    scanf("%d", &n);
    char arr[n];
    printf("Enter the string : ");
    scanf("%s", &arr);
    printf("All the Combination are : \n");
    printArrangements(arr, 0, n - 1, &arrangecount);
    printf("TOTAL NUMBER OF STRINGS: %d", arrangecount);
    return 0;
}