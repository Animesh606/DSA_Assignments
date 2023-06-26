#include <stdio.h>

// Problem 1:
// Write a program in C language to generate first n Fibonacci numbers using:
// 1.	For loop
// 2.	While loop
// 3.	Do-while loop
// where the value of n is taken as input dynamically

void printWithForLoop(int n)
{
    int a = 0, b = 1;
    printf("%d ", a);
    if (n > 1)
        printf("%d ", b);
    if (n > 2)
    {
        for (int i = 2; i < n; i++)
        {
            int c = b;
            b += a;
            a = c;
            printf("%d ", b);
        }
    }
    printf("\n");
}

void printWithWhileLoop(int n)
{
    int a = 0, b = 1;
    printf("%d ", a);
    if (n > 1)
        printf("%d ", b);
    if (n > 2)
    {
        n--;
        while (--n)
        {
            int c = b;
            b += a;
            a = c;
            printf("%d ", b);
        }
    }
    printf("\n");
}

void printWithDoWhileLoop(int n)
{
    int a = 0, b = 1;
    printf("%d ", a);
    if (n > 1)
        printf("%d ", b);
    if (n > 2)
    {
        n -= 2;
        do
        {
            int c = b;
            b += a;
            a = c;
            printf("%d ", b);
        } while (--n);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of element of fibbonacci series: ");
    scanf("%d", &n);
    printf("Fibbonacci using For loop:\n");
    printWithForLoop(n);
    printf("Fibbonacci using while loop:\n");
    printWithWhileLoop(n);
    printf("Fibbonacci using Do While loop:\n");
    printWithDoWhileLoop(n);
    return 0;
}