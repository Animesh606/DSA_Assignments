// Day 12: 
// Problem 1: Write a program in C to implement Binary Search Tree (BST) to perform the following operations:
// 1.	Creation  
// 2.	In order traversal 
// 3.	Post order traversal 
// 4.	Pre order traversal 
// 5.	Searching  
// 6.	Insertion
// 7.	Deletion

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} tnode;

tnode *newNode(int data)
{
    tnode *node = (tnode *)malloc(sizeof(tnode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void insertion(tnode **head, int data)
{
    tnode *node = newNode(data);
    if(*head)
    {
        tnode *ptr = *head;
        while(1)
        {
            if(ptr->data > node->data)
            {
                if(ptr->left)
                    ptr = ptr->left;
                else
                {
                    ptr->left = node;
                    break;
                }
            }
            else
            {
                if(ptr->right)
                    ptr = ptr->right;
                else
                {
                    ptr->right = node;
                    break;
                }
            }
        }
    }
    else
        *head = node;
}

void preorderdisplay(tnode *head)
{
    if(head)
    {
        printf(" %d", head->data);
        preorderdisplay(head->left);
        preorderdisplay(head->right);
    }
}

void postorderdisplay(tnode *head)
{
    if(head)
    {
        postorderdisplay(head->left);
        postorderdisplay(head->right);
        printf(" %d", head->data);
    }
}

void inorderdisplay(tnode *head)
{
    if(head)
    {
        inorderdisplay(head->left);
        printf(" %d", head->data);
        inorderdisplay(head->right);
    }
}


int searching(tnode *head, int data)
{
    if(head)
    {
        tnode *node = head;
        while(node)
        {
            if(data == node->data)
                return 1;
            else if(data < node->data)
                node = node->left;
            else
                node = node->right;
        }
        return 0;
    }
}

void deletion(tnode **head, int data)
{
    if(*head)
    {
        if((*head)->data == data)
        {
            if((*head)->left)
            {
                tnode *temp = (*head)->left;
                if(temp->right)
                {   while(temp->right->right)
                        temp = temp->right;
                    (*head)->data = temp->right->data;
                    temp->right = NULL;
                }
                else
                {
                    int tdata = temp->data;
                    deletion(&(*head), temp->data);
                    (*head)->data = tdata;
                }
            }
            else if((*head)->right)
            {
                tnode *temp = (*head)->right;
                if(temp->left)
                {
                    while(temp->left->left)
                        temp = temp->left;
                    (*head)->data = temp->left->data;
                    temp->left = NULL;
                }
                else
                {
                    int tdata = temp->data;
                    deletion(&(*head), temp->data);
                    (*head)->data = tdata;
                }
            }
            else
                *head = NULL;
        }
        else if((*head)->data > data)
            deletion(&((*head)->left), data);
        else
            deletion(&((*head)->right), data);
    }
    else
        printf("Element not Found!!");
}

void display(tnode *head)
{
    printf("The preorder Traversal : ");
    preorderdisplay(head);
    printf("\n");
    printf("The inorder Traversal : ");
    inorderdisplay(head);
    printf("\n");
    printf("The postorder Traversal : ");
    postorderdisplay(head);
    printf("\n");
}

tnode *creationBST()
{
    tnode *head = NULL;
    int n, data;
    printf("Enter the number of Element : ");
    scanf("%d", &n);
    printf("Enter the list :\n");
    while(n--)
    {
        scanf("%d", &data);
        insertion(&head, data);
    }
    display(head);
    return head;   
}

int main() {
    int chooseoption;
    tnode *start = NULL;
    do
    {
        printf("Enter your choice:\n1. Create a BST\n2. Display\n3. Search an Element\n4. Insert an element\n5. Delete an Element\n0. Exit\n : ");
        scanf("%d", &chooseoption);
        int data, ans;
        switch (chooseoption)
        {
        case 0:
            break;
        case 1:
            start = creationBST();
            break;
        
        case 2:
            display(start);
            break;

        case 3:
            printf("Enter the data : ");
            scanf("%d", &data);
            ans = searching(start, data);
            if(ans)
                printf("%d is present in BST!!!\n", data);
            else
                printf("%d is not present!!!\n");
            break;

        case 4:
            printf("Enter the data : ");
            scanf("%d", &data);
            insertion(&start, data);
            break;

        case 5:
            printf("Enter the data : ");
            scanf("%d", &data);
            deletion(&start, data);
            break;

        default:
            printf("Enter a valid option!!\n");
            break;
        }
    } while(chooseoption);
    return 0;
}