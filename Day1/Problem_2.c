#include <stdio.h>
#include <stdlib.h>

// Problem 2:
// Write a menu driven program in C language to perform the following operations:
// 1.	To check whether a given number is prime or not?
// 2.	To check whether a given number is Armstrong or not?
// 3.	Find out the largest among three numbers.
// 4.	Exit

int makepower(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2)
        return a * makepower(a, n - 1);
    else
    {
        int x = makepower(a, n / 2);
        return x * x;
    }
}
int primeNumber(int n)
{
    if (n == 1)
        return 1;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return 1;
    return 0;
}

int armstrongNumber(int n)
{
    int cc = n, digicount = 0, sum = 0;
    while (cc)
    {
        cc /= 10;
        digicount++;
    }
    cc = n;
    for (int i = 0; i < digicount; i++)
    {
        sum += makepower(cc % 10, digicount);
        cc /= 10;
    }
    return (sum == n);
}
int main()
{
    int chooseOption, num, a, b, c;
    while (1)
    {
        printf("Choose from the following options:\n1.\tCheck whether a given number is prime or not?\n2.\tCheck whether a given number is Armstrong or not?\n3.\tFind out the largest among three numbers.\n4.\tExit\n");
        scanf("%d", &chooseOption);
        switch (chooseOption)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &num);
            if (primeNumber(num))
                printf("%d is not a Prime Number!!!\n", num);
            else
                printf("%d is a prime Number!!!\n", num);
            break;

        case 2:
            printf("Enter the number: ");
            scanf("%d", &num);
            if (armstrongNumber(num))
                printf("%d is a Armstrong Number!!!\n", num);
            else
                printf("%d is not a Armstrong Number!!!\n", num);
            break;

        case 3:
            printf("Enter the three numbers:\n");
            scanf("%d %d %d", &a, &b, &c);
            if (a >= b && a >= c)
                printf("The maximum number is %d\n", a);
            else if (b >= a && b >= c)
                printf("The maximum number is %d\n", b);
            else
                printf("The maximum number is %d\n", c);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please input a valid number!!!");
        }
    }
    return 0;
}