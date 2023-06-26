#include <stdio.h>
#include <stdlib.h>

// Problem 1: Write a program in C to perform the following operation of single Dynamic Circular Linked List:
// 1. Creation
// 2. Display
// 3. Insertion
// 4. Deletion
// 5. Searching

typedef struct CircularLinkedlistNode
{
    int data;
    struct CircularLinkedlistNode *next;
} node;

node *createLinkedList()
{
    node *head = NULL;
    int n, value;
    printf("Enter the numer of data : ");
    scanf("%d", &n);
    if (n > 0)
    {
        node *ptr = (node *)malloc(sizeof(node));
        printf("Enter all data : \n");
        scanf("%d", &ptr->data);
        head = ptr;
        for (int i = 1; i < n; i++)
        {
            node *temp = (node *)malloc(sizeof(node));
            scanf("%d", &temp->data);
            ptr = ptr->next = temp;
        }
        ptr->next = head;
    }
    return head;
}

void displayLinkedlist(node *head)
{
    node *ptr = head;
    if (ptr == NULL)
    {
        printf("No Element to be display!!\n");
        return;
    }
    printf("Head");
    do
    {
        printf(" -> %d", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf(" -> Head\n");
}

void insertEliment(node **head, int data, int pos)
{
    if (pos < 1)
        printf("Enter a valid index!!\n");
    else if (pos == 1)
    {
        node *ptr = (node *)malloc(sizeof(node)), *temp;
        ptr->data = data;
        ptr->next = *head;
        if(*head)
        {
            temp = *head;
            while(temp->next != *head)
                temp = temp->next;
            temp->next = ptr;
        }
        else
            ptr->next = ptr;
        *head = ptr;
    }
    else if(pos == 2 && *head != NULL)
    {
        node *ptr = (node *)malloc(sizeof(node));
        ptr->data = data;
        ptr->next = (*head)->next;
        (*head)->next = ptr;
    }
    else if(*head != NULL)
    {
        node *ptr = *head;
        int i = 2;
        do
        {
            ptr = ptr->next;
            i++;
        } while (i < pos && ptr != *head);
        if(ptr == *head)
            printf("Enter a valid index!!\n");
        else
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->data = data;
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    else
        printf("Enter a valid index!!\n");
}

void deletionElement(node **head, int pos)
{
    if(pos < 1)
        printf("Enter a valid position!!\n");
    else if(*head == NULL)
        printf("No Element to be deleted!!\n");
    else if(pos == 1)
    {
        node *temp = *head;
        if((*head)->next == *head)
            *head = NULL;
        else
        {
            *head = (*head)->next;
            node *ptr = *head;
            while(ptr->next != temp)
                ptr = ptr->next;
            ptr->next = *head;
        }
        free(temp);
    }
    else if(pos == 2 && (*head)->next != *head)
    {
        node *temp = (*head)->next;
        (*head)->next = temp->next;
        free(temp);
    }
    else
    {
        node *temp = *head;
        int i = 2;
        while(temp->next->next != *head && i < pos)
        {
            temp = temp->next;
            i++;
        }
        if((temp->next->next != *head) || (i = pos - 1))
        {
            node *ptr = temp->next;
            temp->next = temp->next->next;
            free(ptr);
        }
        else
            printf("Enter a valid index!!\n");
    }
}

int searchEliment(node *head, int data)
{
    if(head == NULL)
        return -1;
    else if(head->data == data)
        return 1;
    else
    {
        int i = 2;
        node *temp = head->next;
        while(temp != head)
        {
            if(temp->data == data)
                return i;
            i++;
            temp = temp->next;
        }
        return -1;
    }
}

int main()
{
    int chooseOption;
    node *start = NULL;
    while (1)
    {
        printf("Choose an option:\n1. Create a Circular Linkedlist\n2. Display\n3. Insert an element\n4. Delete an element\n5. Search an element\n0. Exit\n : ");
        scanf("%d", &chooseOption);
        switch (chooseOption)
        {
        case 0:
            exit(0);
            break;

        case 1:
            start = createLinkedList();
            break;

        case 2:
            displayLinkedlist(start);
            break;

        case 3:
            int data, pos;
            printf("Enter the position where to insert : ");
            scanf("%d", &pos);
            printf("Enter a data to be inserted : ");
            scanf("%d", &data);
            insertEliment(&start, data, pos);
            break;

        case 4:
            printf("Enter the position to be deleted : ");
            scanf("%d", &pos);
            deletionElement(&start, pos);
            break;

        case 5:
            printf("Enter the data to be find : ");
            scanf("%d", &data);
            pos = searchEliment(start, data);
            if(pos == -1)
                printf("Not Found!!\n");
            else
                printf("%d is present at %dth position!!\n", data, pos);
            break;

        default:
            printf("Choose an valid option\n");
            break;
        }
    }
    return 0;
}