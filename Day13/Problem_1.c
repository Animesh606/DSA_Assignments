// Problem 1:
//     Write a program in C to implement Heap Tree (Max Heap) using Array to perform the following operations: 
//     1.	Creation 
//     2.	In order traversal 
//     3.	Post-order traversal  
//     4.	Pre-order traversal 
//     5.	Sorting 
//     6.	Display the original list and sorted list

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 30

int arr[max];
int x = -1;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int val)
{
    x += 1;
    arr[x] = val;
    int i = x;
    while (i > 0)
    {
        int parent = ((i - 1) / 2);
        if (arr[parent] < arr[i])
        {
            swap(&arr[parent], &arr[i]);
            i = parent;
        }
        else
            return;
    }
}
void creat()
{
    printf("Please enter the size of the array-");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("PLease enter the value-");
        int val;
        scanf("%d", &val);
        insert(val);
    }
}
void inorder(int i)
{
    if (i <= x)
    {
        inorder(2 * i + 1);
        printf("%d ", arr[i]);
        inorder(2 * i + 2);
    }
}
void Preorder(int i)
{
    if (i <= x)
    {
        printf("%d ", arr[i]);
        Preorder(2 * i + 1);
        Preorder(2 * i + 2);
    }
}
void Postorder(int i)
{
    if (i <= x)
    {
        Postorder(2 * i + 1);
        Postorder(2 * i + 2);
        printf("%d ", arr[i]);
    }
}
void heapify(int i,int n)
{
 int largest=i;
 int l=2*i+1;
 int r=2*i+2;
 if(l< n&&arr[largest]<arr[l])
 largest=l;
 if(r< n&&arr[largest]<arr[r])
 largest=r;
 if(largest!=i)
 {
    swap(&arr[largest],&arr[i]);
    heapify(largest,n);
 }

}
void display()
{
    printf("The heap sorted array is-");
    for(int i=0;i<=x;i++)
    printf(" %d ",arr[i]);
}
void heap_sort()
{
  for(int i=x;i>=0;i--)
  {
    swap(&arr[0],&arr[i]);
    heapify(0,i);
  }
  display();
}
int main()
{
    while (1)
    {
        printf("\n1.creat \n2.display \n  a.inorder traversal \n  b.Postorder traversal \n  c.Preorder traversal\n3.sort\n4 exit\n");
        printf("please choose what you want-");
        int choise;
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            creat();
            break;
        case 2:
            printf("\nThe inorder traversal is--");
            inorder(0);
            printf("\nThe postorder traversal is--");
            Postorder(0);
            printf("\nThe preorder traversal is--");
            Preorder(0);
            break;
        case 3:
            heap_sort();
            break;
        case 4:
            exit(0);
        default:
            printf("choose currect number----");
        }
    }
    return 0;
}