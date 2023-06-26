#include <stdio.h>
#include <stdlib.h>

// Problem 1: Write a program in C to perform the following operation of single Dynamic Linked List:
// 1. Creation
// 2. Display
// 3. Display using recursive function
// 4. Searching
// 5. Insertion
// 6. Deletion
// 7. Reverse print
// 8. Reverse Linked List

typedef struct node
{
    int data;
    struct node *next;
} nd;

nd *creatlinklist()
{
    int n;
    nd *head = NULL;
    printf("Enter the number of data: ");
    scanf("%d", &n);
    if (n > 0)
    {
        nd *ptr = (nd *)malloc(sizeof(nd));
        printf("Enter the data: \n");
        scanf("%d", &ptr->data);
        head = ptr;
        for (int i = 1; i < n; i++)
        {
            nd *temp = (nd *)malloc(sizeof(nd));
            scanf("%d", &temp->data);
            ptr = ptr->next = temp;
        }
        ptr->next = NULL;
    }
    return head;
}

void display(nd *head)
{
    nd *ptr = head;
    printf("start");
    while (ptr)
    {
        printf(" -> %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" -> NULL\n");
}

void display_recursion(nd *head)
{
    if (head)
    {
        printf(" -> %d", head->data);
        display_recursion(head->next);
    }
    else
        printf(" -> NULL\n");
}

int search(nd *head, int x)
{
    nd *ptr = head;
    int index = 1;
    while (ptr)
    {
        if (ptr->data == x)
            return index;
        ptr = ptr->next;
        index++;
    }
    return -1;
}

void insert(nd **head, int data, int pos)
{
    if (pos < 1)
        printf("Invalid position!!\n");
    else if (pos == 1)
    {
        nd *ptr = (nd *)malloc(sizeof(nd));
        ptr->data = data;
        ptr->next = *head;
        *head = ptr;
    }
    else if (*head == NULL)
        printf("Invalid Position!!");
    else
    {
        nd *temp = *head, *ptr = (nd *)malloc(sizeof(nd));
        int i = 2;
        while (i < pos && temp)
        {
            temp = temp->next;
            i++;
        }
        if (temp)
        {
            ptr->data = data;
            ptr->next = temp->next;
            temp->next = ptr;
        }
        else
            printf("Invalid Position!!");
    }
}

void delete (nd **head, int pos)
{
    if (pos < 1 || *head == NULL)
        printf("Invalid Position!!\n");
    else if (pos == 1)
    {
        nd *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        nd *temp = *head;
        for (int i = 2; i < pos && temp->next; i++)
            temp = temp->next;
        if (temp->next)
        {
            nd *ptr = temp->next;
            temp->next = temp->next->next;
            free(ptr);
        }
        else
            printf("Invalid Position!!\n");
    }
}

void display_reverse(nd *head)
{
    if (head)
    {
        display_reverse(head->next);
        printf(" -> %d", head->data);
    }
}

nd *reverse(nd *head)
{
    nd *prev = NULL, *curr = head, *nextlist = head;
    while (curr)
    {
        nextlist = nextlist->next;
        curr->next = prev;
        prev = curr;
        curr = nextlist;
    }
    return prev;
}

int main()
{
    int choice;
    nd *start = NULL;
    while (1)
    {
        printf("Enter your choice:\n1. Create linklist\n2. Display linklist\n3. Display using recursive Function\n4. Search an eliment\n5. Insert a data\n6. Delete an eliment\n7. Reverse print\n8. Reverse the linklist\n0. Exit\n :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;

        case 1:
            start = creatlinklist();
            break;

        case 2:
            display(start);
            break;

        case 3:
            printf("start");
            display_recursion(start);
            break;

        case 4:
            int x, pos;
            printf("Enter the element to be search: ");
            scanf("%d", &x);
            int searchresult = search(start, x);
            if (searchresult == -1)
                printf(" <-- The eliment is not present -->\n");
            else
                printf(" <-- %d is present on %dth position --> \n", x, searchresult);
            break;

        case 5:
            printf("Enter position where to be inserted : ");
            scanf("%d", &pos);
            printf("Enter the data : ");
            scanf("%d", &x);
            insert(&start, x, pos);
            break;

        case 6:
            printf("Enter position which wanted to be deleted :");
            scanf("%d", &pos);
            delete (&start, pos);
            break;

        case 7:
            printf("Start");
            display_reverse(start);
            printf(" -> NULL\n");
            break;

        case 8:
            start = reverse(start);
            break;

        default:
            printf(" <-- Please enter a valid choice --> \n");
            break;
        }
    }
    return 0;
}