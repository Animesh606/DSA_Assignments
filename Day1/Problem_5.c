#include <stdio.h>

// Problem 5:
// Write a program in C language to calculate the length of given string and reverse this given string without using any string library function.

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n = 0;
    char str[100];
    printf("Enter the string : ");
    scanf("%s", str);
    while (n < 100 && str[n])
        n++;
    printf("The length of the string is %d\n", n);
    for (int i = 0; i < n / 2; i++)
        swap(&str[i], &str[n - i - 1]);
    printf("The reverse string is %s", str);
    return 0;
}