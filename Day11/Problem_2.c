#include <stdio.h>

void tower_of_hanoi(int n, char A, char B, char C)
{
    if(n == 0)
        return;
    tower_of_hanoi(n - 1, A, C, B);
    printf("Shift rock from %c to %c\n", A, C);
    tower_of_hanoi(n - 1, B, A, C);
}

int main() {
    int n;
    printf("Enter the Number : ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}