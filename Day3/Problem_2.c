#include <stdio.h>
#include <string.h>

// Problem 2:
// Write a menu driven program in C to implement the following basic operations of FILE:
// 1.	Reading a file.
// 2.	Writing a file.
// 3.	Closing a file.
// 4.	Reading and writing strings to file.
// 5.	Reading and writing binary files.

int main()
{
    int chooseoption;
    while (1)
    {
        printf("\nChoose an option:\n1. Reading a file.\n2. Writing a file.\n3. Closing a file.\n4. Reading and writing strings to file.\n5. Reading and writing binary files.\n : ");
        fflush(stdin);
        scanf("%d", &chooseoption);
        if (chooseoption == 1)
        {
            FILE *ptr;
            ptr = fopen("text.txt", "r");
            if (ptr == NULL)
                printf("No content in the file!!");
            else
            {
                printf("The content of file are: \n");
                char ch;
                do
                {
                    ch = fgetc(ptr);
                    printf("%c", ch);
                } while (ch != EOF);
            }
            printf("\n");
            fclose(ptr);
        }
        else if (chooseoption == 2)
        {
            FILE *ptr;
            char str[200];
            ptr = fopen("text.txt", "w");
            printf("Please write the contents:\n");
            fflush(stdin);
            gets(str);
            fputs(str, ptr);
            fclose(ptr);
        }
        else if (chooseoption == 3)
        {
            FILE *ptr;
            printf("closing file...\n");
            fclose(ptr);
            break;
        }
        else if (chooseoption == 4)
        {
            FILE *ptr;
            ptr = fopen("text.txt", "r+");
            if (ptr == NULL)
                printf("No content in the file!!");
            else
            {
                printf("The content of file are: \n");
                char ch;
                do
                {
                    ch = fgetc(ptr);
                    printf("%c", ch);
                } while (ch != EOF);
            }
            printf("\n");
            printf("Add more contents :\n");
            char str[200];
            fputs("\n", ptr);
            fflush(stdin);
            gets(str);
            fputs(str, ptr);
            fclose(ptr);
        }
        else if (chooseoption == 5)
        {
            FILE *ptr;
            ptr = fopen("aka.bin", "ab+");
            char str[300];
            fread(str, sizeof(str), 1, ptr);
            printf("The contents of the file are :\n%s\n", str);
            char xtr[300];
            printf("Add more content: ");
            fflush(stdin);
            scanf("%[^\n]s", xtr);
            fwrite(xtr, strlen(xtr) * 1, 1, ptr);
            fclose(ptr);
        }
        else
            printf("Please enter a valid options!!!!");
    }
    return 0;
}