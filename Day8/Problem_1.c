#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Problem 1: Write a program in C to perform the following operation of single Dynamic Double Linked List:
// 1. Creation
// 2. Display
// 3. Display using recursive function
// 4. Searching
// 5. Insertion
// 6. Deletion
// 7. Reverse print
// 8. Reverse Linked List

typedef struct doubleLinkedListNode
{
    int data;
    struct doubleLinkedListNode *next, *prev;
} node;

void printdoubleLinkedlist(node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
    }
    else
    {
        printf("Start ->");
        node *ptr = head;
        while (ptr != NULL)
        {
            printf(" %d ->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int length(node *head)
{
    node *ptr = head;
    int count = 0;
    while (ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

node *creation(node *head)
{
    node *newnode, *temp;
    head = NULL;
    char choice = 'y';
    while (choice == 'y')
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter data\n");
        scanf("%d", &newnode->data);
        newnode->next = newnode->prev = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Do you want to continue(y/n) ?  ");
        fflush(stdin);
        scanf("%c", &choice);
    }
    return head;
}
node *deletion(node *head)
{
    if (head)
    {
        int pos, len = length(head);
        printf("Enter the position\n");
        scanf("%d", &pos);
        if (pos < 1 || pos > len)
        {
            printf("Invalid position\n");
        }
        else if (pos == 1)
        {
            node *p = head;
            if (head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    free(p);
                }
                else
                {
                    head = head->next;
                    head->prev = NULL;
                    free(p);
                }
            }
            return head;
        }
        else if (pos == len)
        {
            node *p = head;
            if (head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    free(p);
                }
                else
                {
                    while (p->next != NULL)
                    {
                        p = p->next;
                    }
                    node *q = p->prev;
                    q->next = NULL;
                    free(p);
                }
            }
            return head;
        }
        else
        {
            node *p = head;
            int i = 1;
            while (i != pos - 1)
            {
                i++;
                p = p->next;
            }
            node *q = p->next;
            p->next = q->next;
            q->next->prev = p;
            free(q);
        }
        return head;
    }
    else
        printf("Please create the linked list first !");
}

node *insertion(node *head)
{
    int pos, len = length(head);
    printf("Enter the position\n");
    scanf("%d", &pos);
    if (pos < 1 || pos > len + 1)
        printf("Invalid position!!\n");
    else if (pos == 1)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->prev = newnode->next = NULL;
        printf("Enter all data : \n");
        scanf("%d", &newnode->data);
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
        return head;
    }
    else if (pos == len + 1)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->prev = NULL;
        newnode->next = NULL;
        printf("Enter data\n");
        scanf("%d", &newnode->data);
        node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = newnode;
        newnode->prev = p;
        return head;
    }
    else
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->prev = newnode->next = NULL;
        printf("Enter data\n");
        scanf("%d", &newnode->data);
        int i = 1;
        node *p = head;
        while (i != pos - 1)
        {
            i++;
            p = p->next;
        }
        newnode->next = p->next;
        newnode->prev = p;
        p->next->prev = newnode;
        p->next = newnode;
    }
    return head;
}

void searching(node *start)
{
    printf("Enter the element that you want to search\n");
    int val, pos = 0;
    scanf("%d", &val);
    node *ptr = start;
    while (ptr)
    {
        pos++;
        if (ptr->data == val)
        {
            printf("The position of the element is : %d\n", pos);
            return;
        }
        ptr = ptr->next;
    }
    printf("Element is not found\n");
}

node *reverse(node *head)
{
    node *tail;
    if (head == NULL)
        printf("List is empty!!\n");
    else
    {
        node *currnode, *nextnode;
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        currnode = head;
        while (currnode != NULL)
        {
            nextnode = currnode->next;
            currnode->next = currnode->prev;
            currnode->prev = nextnode;
            currnode = nextnode;
        }
        currnode = head;
        head = tail;
        tail = currnode;
    }
    return head;
}
int main()
{
    node *start = NULL;
    while (1)
    {
        int choice;
        printf("Enter a choice\n1: Creation \n2. Deletion \n3: Search \n4: Display \n5: Insertion \n6: Reverse \n0: Exit \n : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = creation(start);
            break;

        case 2:
            start = deletion(start);
            break;

        case 3:
            searching(start);
            break;

        case 4:
            printdoubleLinkedlist(start);
            break;

        case 5:
            start = insertion(start);
            break;

        case 6:
            start = reverse(start);
            break;

        case 0:
            exit(0);
            break;

        default:
            printf("Please enter an valid option!!\n");
        }
    }
    return 0;
}