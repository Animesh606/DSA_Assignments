#include <stdio.h>
#include <stdlib.h>

// Problem 1:
// Write a program in C to implement:
// 1.	Static queue
// 2.	Dynamic queue
// 3.	Circular queue
// to perform the following operations: 
// a.	Insert
// b.	Delete
// c.	Display

typedef struct static_queue
{
    int front, rear, *arr, maxsize;
} squeue;
typedef struct dynamic_queue
{
    int data;
    struct dynamic_queue *next;
} dqueue;
typedef struct circular_queue
{
    int front, rear, *arr, maxsize;
} cqueue;

squeue *createStaticQueue(int size)
{
    squeue *q1 = (squeue *)malloc(sizeof(squeue));
    q1->front = 0;
    q1->rear = -1;
    q1->arr = (int *)malloc(size * sizeof(int));
    q1->maxsize = size;
    return q1;
}
cqueue *createCircularQueue(int size)
{
    cqueue *q1 = (cqueue *)malloc(sizeof(cqueue));
    q1->front = 0;
    q1->rear = 0;
    q1->maxsize = size;
    q1->arr = (int *)malloc(size * sizeof(int));
    return q1;
}

void insert_static_queue(squeue *q1, int data)
{
    if (q1->rear == q1->maxsize - 1)
        printf("Insertion is not possible!!\n");
    else
        q1->arr[++q1->rear] = data;
}
void insert_dynamic_queue(dqueue **front, dqueue **rear, int data)
{
    dqueue *dq1 = (dqueue *)malloc(sizeof(dqueue));
    dq1->data = data;
    dq1->next = NULL;
    if (*front == NULL && *rear == NULL)
        *front = *rear = dq1;
    else
        *rear = (*rear)->next = dq1;
}
void insert_circular_queue(cqueue *q1, int data)
{
    if ((q1->rear + 1) % q1->maxsize == q1->front)
        printf("No element can be inserted!!\n");
    else
    {
        q1->arr[q1->rear] = data;
        q1->rear = (q1->rear + 1) % q1->maxsize;
    }
}

void delete_static_queue(squeue *q1)
{
    if (q1->front > q1->rear)
        printf("Queue is already empty!!\n");
    else
        q1->front++;
}
void delete_dynamic_queue(dqueue **front, dqueue **rear)
{
    if (*front == NULL)
        printf("No Element to delete!!\n");
    else
    {
        dqueue *temp = *front;
        if (*front == *rear)
            *rear = NULL;
        *front = (*front)->next;
        free(temp);
    }
}
void delete_circular_queue(cqueue *q1)
{
    if (q1->front == q1->rear)
        printf("Queue is empty!!\n");
    else
        q1->front = (q1->front + 1) % q1->maxsize;
}

void display_static_queue(squeue *q1)
{
    if (q1->front > q1->rear)
        printf("Queue is empty!!\n");
    else
    {
        printf("Front");
        for (int i = q1->front; i <= q1->rear; i++)
            printf(" -> %d", q1->arr[i]);
        printf(" <- Rear\n");
    }
}
void display_dynamic_queue(dqueue *front)
{
    if (front == NULL)
        printf("No Element found!!\n");
    else
    {
        dqueue *temp = front;
        printf("front");
        while (temp != NULL)
        {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
        printf(" <- rear\n");
    }
}
void display_circular_queue(cqueue *q1)
{
    if (q1->front == q1->rear)
        printf("Queue is empty!!\n");
    else
    {
        printf("Front");
        for (int i = q1->front; i < q1->rear; i = (i + 1) % q1->maxsize)
            printf(" -> %d", q1->arr[i]);
        printf(" <- Rear\n");
    }
}

int main()
{
    int choosequeue, chooseoperation;
    do
    {
        printf("Choose a queue to operate :\n1. Static Queue\n2. Dynamic Queue\n3. Circular Queue\n0. Exit\n :");
        scanf("%d", &choosequeue);
        squeue *sq1 = createStaticQueue(10);
        dqueue *dq1_front = NULL, *dq1_rear = NULL;
        cqueue *cq1 = createCircularQueue(10);
        int data;
        switch (choosequeue)
        {
        case 1:
            do
            {
                printf("Choose an operation :\n1. Insert\n2. Delete\n3. Display\n0. Exit\n : ");
                scanf("%d", &chooseoperation);
                switch (chooseoperation)
                {
                case 1:
                    printf("Enter the data : ");
                    scanf("%d", &data);
                    insert_static_queue(sq1, data);
                    break;

                case 2:
                    delete_static_queue(sq1);
                    break;

                case 3:
                    display_static_queue(sq1);
                    break;

                case 0:
                    printf("Back to main menu...\n");
                    break;

                default:
                    printf("Choose an valid option!!\n");
                    break;
                }
            } while(chooseoperation);
            break;

        case 2:
            do
            {
                printf("Choose an operation :\n1. Insert\n2. Delete\n3. Display\n0. Exit\n : ");
                scanf("%d", &chooseoperation);
                switch (chooseoperation)
                {
                case 1:
                    printf("Enter the data : ");
                    scanf("%d", &data);
                    insert_dynamic_queue(&dq1_front, &dq1_rear, data);
                    break;

                case 2:
                    delete_dynamic_queue(&dq1_front, &dq1_rear);
                    break;

                case 3:
                    display_dynamic_queue(dq1_front);
                    break;

                case 0:
                    printf("Back to main menu...\n");
                    break;

                default:
                    printf("Choose an valid option!!\n");
                    break;
                }
            } while (chooseoperation);
            break;

        case 3:
            do
            {
                printf("Choose an operation :\n1. Insert\n2. Delete\n3. Display\n0. Exit\n : ");
                scanf("%d", &chooseoperation);
                switch (chooseoperation)
                {
                case 1:
                    printf("Enter the data : ");
                    scanf("%d", &data);
                    insert_circular_queue(cq1, data);
                    break;

                case 2:
                    delete_circular_queue(cq1);
                    break;

                case 3:
                    display_circular_queue(cq1);
                    break;

                case 0:
                    printf("Back to main menu...\n");
                    break;

                default:
                    printf("Choose an valid option!!\n");
                    break;
                }
            } while (chooseoperation);
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Enter a valid queue!!\n");
            break;
        }
    } while (choosequeue);
    return 0;
}