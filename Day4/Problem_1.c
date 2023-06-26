// Write a menu driven program in c to implement the following basic operation of a FILE :
//  1. Print the contents of file
//  2. Copy contents of one file to another file
//  3. Merge content of two file into a third file
//  4. Delete a specific file

#include <stdio.h>
#include <stdlib.h>

void printfile(FILE *filename)
{
    int ch = getc(filename);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(filename);
    }
    printf("\n");
}

void copyfile(FILE *filename2, FILE *filename1)
{
    int ch = getc(filename1);
    while (ch != EOF)
    {
        putc(ch, filename2);
        ch = getc(filename1);
    }
}

void mergefile(FILE *filename3, FILE *filename1, FILE *filename2)
{
    int ch = getc(filename1);
    while (ch != EOF)
    {
        putc(ch, filename3);
        ch = getc(filename1);
    }
    putc('\n', filename3);
    ch = getc(filename2);
    while (ch != EOF)
    {
        putc(ch, filename3);
        ch = getc(filename2);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Print the contents of FILE: \n2. Copy contents of one file to another file: \n3. Merge content of two file into a third file: \n4. Delete a specific file: \n0. Exit\n Choose an option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            char filename[20], filename1[20], filename2[20], filename3[20];
            FILE *ptr, *ptr1, *ptr2, *ptr3;
            printf("Enter the file name: \n");
            scanf("%s", &filename);
            ptr = fopen(filename, "r");
            printfile(ptr);
            fclose(ptr);
            break;

        case 2:
            printf("copy from : ");
            scanf("%s", &filename1);
            printf("copy to : ");
            scanf("%s", &filename2);
            ptr1 = fopen(filename1, "r");
            ptr2 = fopen(filename2, "w");
            copyfile(ptr2, ptr1);
            fclose(ptr1);
            fclose(ptr2);
            break;

        case 3:
            printf("1st filename : ");
            scanf("%s", &filename1);
            printf("2nd filename : ");
            scanf("%s", &filename2);
            printf("new filename : ");
            scanf("%s", &filename3);
            ptr1 = fopen(filename1, "r");
            ptr2 = fopen(filename2, "r");
            ptr3 = fopen(filename3, "w");
            mergefile(ptr3, ptr1, ptr2);
            fclose(ptr1);
            fclose(ptr2);
            fclose(ptr3);
            break;

        case 4:
            printf("Enter the filename : ");
            scanf("%s", &filename);
            remove(filename);
            break;

        case 0:
            exit(0);

        default:
            printf("Enter a valid option!!");
            break;
        }
    }
    return 0;
}