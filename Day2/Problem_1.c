#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

// Problem 1:
// Write a menu driven program in C to create the diagrams of the Circle, Rectangle and Triangle using functions and perform the following operations on your created diagrams:
// 1.	Translation operation.
// 2.	Rotation operation with respect to a given point.
// 3.	Scaling operation.

void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x1, y1, x3, y3);
}

int main()
{
    int chooseoption, chooseoperation, gd = DETECT, gm, x, y, r, x1, y1, m, x2, y2, x3, y3;
    float theta;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    clrscr();
    while (1)
    {
        clrscr();
        printf("Choose an option to draw:\n1. Circle\n2. Rectangle\n3. Triangle\n0. Exit\n");
        scanf("%d", &chooseoption);
        if (chooseoption == 1)
        {
            printf("Enter position of centre of circle (x y): ");
            scanf("%d %d", &x, &y);
            printf("Enter size of radius : ");
            scanf("%d", &r);
            while (1)
            {
                clrscr();
                circle(x, y, r);
                printf("Choose an operation : \n1. Translation\n2. Rotation\n3. Scaling\n0. Exit\n : ");
                scanf("%d", &chooseoperation);
                if (chooseoperation == 0)
                    break;
                switch (chooseoperation)
                {
                case 1:
                    printf("Enter the shifting distance along x and y (x y) : ");
                    scanf("%d %d", &x1, &y1);
                    circle(x + x1, y + y1, r);
                    break;

                case 2:
                    printf("Enter the coordinate of centre of rotation (x y): ");
                    scanf("%d %d", &x1, &y1);
                    printf("Enter the angle of rotation (in degree) : ");
                    scanf("%f", &theta);
                    theta = (theta * M_PI) / 180;
                    circle(x1 + (x - x1) * cos(theta) - (y - y1) * sin(theta), y1 + (y - y1) * cos(theta) + (x - x1) * sin(theta), r);
                    break;

                case 3:
                    printf("Enter the scaling number : ");
                    scanf("%d", &m);
                    circle(x, y, m * r);
                    break;

                default:
                    break;
                }
                getch();
            }
        }
        else if (chooseoption == 2)
        {
            printf("Enter coordinates of two opposite point of rectangle (x1 y1 x2 y2): ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            while (1)
            {
                clrscr();
                rectangle(x1, y1, x2, y2);
                printf("Choose an operation : \n1. Translation\n2. Rotation\n3. Scaling\n0. Exit\n : ");
                scanf("%d", &chooseoperation);
                if (chooseoperation == 0)
                    break;
                switch (chooseoperation)
                {
                case 1:
                    printf("Enter the shifting distance along x and y (x y) : ");
                    scanf("%d %d", &x, &y);
                    rectangle(x1 + x, y1 + y, x2 + x, y2 + y);
                    break;

                case 2:
                    printf("Enter the coordinate of centre of rotation (x y): ");
                    scanf("%d %d", &x, &y);
                    printf("Enter the angle of rotation (in degree) : ");
                    scanf("%f", &theta);
                    theta = (theta * M_PI) / 180;
                    rectangle(x + (x1 - x) * cos(theta) - (y1 - y) * sin(theta), y + (y1 - y) * cos(theta) + (x1 - x) * sin(theta), x + (x2 - x) * cos(theta) - (y2 - y) * sin(theta), y + (y2 - y) * cos(theta) + (x2 - x) * sin(theta));
                    break;

                case 3:
                    printf("Enter the scaling number : ");
                    scanf("%d", &m);
                    rectangle(x1, y1, x1 + (x2 - x1) * m, y1 + (y2 - y1) * m);
                    getch();
                    break;

                default:
                    break;
                }
                getch();
            }
        }
        else if (chooseoption == 3)
        {
            printf("Enter 1st coordinate of the triangle (x1 y1): ");
            scanf("%d %d", &x1, &y1);
            printf("Enter 2nd coordinate of the triangle (x2 y2): ");
            scanf("%d %d", &x2, &y2);
            printf("Enter 3rd coordinate of the triangle (x3 y3): ");
            scanf("%d %d", &x3, &y3);
            while (1)
            {
                clrscr();
                triangle(x1, y1, x2, y2, x3, y3);
                printf("Choose an operation : \n1. Translation\n2. Rotation\n3. Scaling\n0. Exit\n : ");
                scanf("%d", &chooseoperation);
                if (chooseoperation == 0)
                    break;
                switch (chooseoperation)
                {
                case 1:
                    printf("Enter the shifting distance along x and y (x y) : ");
                    scanf("%d %d", &x, &y);
                    triangle(x1 + x, y1 + y, x2 + x, y2 + y, x3 + x, y3 + y);
                    break;

                case 2:
                    printf("Enter the coordinate of centre of rotation (x y): ");
                    scanf("%d %d", &x, &y);
                    printf("Enter the angle of rotation (in degree) : ");
                    scanf("%f", &theta);
                    theta = (theta * M_PI) / 180;
                    triangle(x + (x1 - x) * cos(theta) - (y1 - y) * sin(theta), y + (y1 - y) * cos(theta) + (x1 - x) * sin(theta), x + (x2 - x) * cos(theta) - (y2 - y) * sin(theta), y + (y2 - y) * cos(theta) + (x2 - x) * sin(theta), x + (x3 - x) * cos(theta) - (y3 - y) * sin(theta), y + (y3 - y) * cos(theta) + (x3 - x) * sin(theta));
                    break;

                case 3:
                    printf("Enter the scaling number : ");
                    scanf("%d", &m);
                    triangle(x1, y1, x1 + (x2 - x1) * m, y1 + (y2 - y1) * m, x1 + (x3 - x1) * m, y1 + (y3 - y1) * m);
                    break;

                default:
                    break;
                }
                getch();
            }
        }
        else if (chooseoption == 0)
            break;
        else
            printf("you have entered wrong option!!!");
        getch();
    }
    closegraph();
    return 0;
}