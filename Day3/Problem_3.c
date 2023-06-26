#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Problem 3:
// Write a menu driven program in C to read name and marks of n number of students from user and stores them in a file and perform the following operations using functions:
// 1.	Append new record of a student to the existing file.
// 2.	Delete a record of a specific student.
// 3.	Update a field of student.
// 4.	Display all records

typedef struct student
{
    char *name;
    int roll_no, dsa, co, de;
} student;

void createrecords(char filename[])
{
    char *name = (char *)calloc(30, sizeof(char));
    int roll_no, dsa, co, de;
    printf("Enter your name: ");
    fflush(stdin);
    gets(name);
    printf("Enter your roll no.: ");
    scanf("%d", &roll_no);
    printf("Enter your Data Structure and Algorithm Marks : ");
    scanf("%d", &dsa);
    printf("Enter your Computer Organisation Marks : ");
    scanf("%d", &co);
    printf("Enter your Digital Electronics Marks : ");
    scanf("%d", &de);
    student st = {name, roll_no, dsa, co, de};
    FILE *ptr = fopen(filename, "ab");
    fwrite(&st, sizeof(st), 1, ptr);
    fclose(ptr);
}

void updaterecord(student *st)
{
    int cd;
    printf("What field do you want to update?\n1. Name\n2. Roll No.\n3. Data Structure & Algorithm Marks\n4. Computer Organisation Marks\n5. Digital Electronics Marks\n : ");
    scanf("%d", &cd);
    switch (cd)
    {
    case 1:
        char *name = (char *)calloc(30, sizeof(char));
        printf("Enter New Name : ");
        fflush(stdin);
        gets(name);
        st->name = name;
        break;

    case 2:
        int roll;
        printf("Enter New Roll No. : ");
        scanf("%d", &roll);
        st->roll_no = roll;
        break;

    case 3:
        int dsa;
        printf("Enter New Data Structure & Algorithm Marks : ");
        scanf("%d", &dsa);
        st->dsa = dsa;
        break;

    case 4:
        int co;
        printf("Enter New Computer Organisation Marks : ");
        scanf("%d", &co);
        st->co = co;
        break;

    case 5:
        int de;
        printf("Enter New Digital Electronics Marks : ");
        scanf("%d", &de);
        st->de = de;
        break;

    default:
        printf("Invalid option!!");
        break;
    }
}

void delete_update_record(char filename[], int ud)
{
    student st;
    int cd, find = 0;
    printf("Choose an option:\n1. Search by Name\n2. Search by Roll No.\n : ");
    scanf("%d", &cd);
    FILE *ptr, *tmp;
    if (cd == 1)
    {
        char *name = (char *)calloc(30, sizeof(char));
        printf("Enter name of the student: ");
        fflush(stdin);
        gets(name);
        ptr = fopen(filename, "rb");
        tmp = fopen("xyz.bin", "wb");
        while (fread(&st, sizeof(student), 1, ptr))
        {
            if (strcmp(st.name, name))
                fwrite(&st, sizeof(student), 1, tmp);
            else
            {
                find = 1;
                if (ud)
                {
                    updaterecord(&st);
                    fwrite(&st, sizeof(student), 1, tmp);
                }
            }
        }
    }
    else if (cd == 2)
    {
        int roll;
        printf("Enter Roll No of the student: ");
        scanf("%d", &roll);
        ptr = fopen(filename, "rb");
        tmp = fopen("xyz.bin", "wb");
        while (fread(&st, sizeof(student), 1, ptr))
        {
            if (st.roll_no != roll)
                fwrite(&st, sizeof(student), 1, tmp);
            else
            {
                find = 1;
                if (ud)
                {
                    updaterecord(&st);
                    fwrite(&st, sizeof(student), 1, tmp);
                }
            }
        }
    }
    else
        printf("Invalid option!!\n");
    fclose(ptr);
    fclose(tmp);
    remove(filename);
    rename("xyz.bin", filename);
    if (find)
        printf("Record found and deleted!!\n");
    else
        printf("Record Not Found!!\n");
}

void displayrecords(char filename[])
{
    student st;
    FILE *ptr = fopen(filename, "rb");
    if (ptr == NULL)
    {
        printf("error!!!\n");
        exit(1);
    }
    while (fread(&st, sizeof(student), 1, ptr))
        printf("Name : %s \nRoll No. : %d \nData Structure & Algorithm : %d \nComputer Organisation : %d \nDigital Electronics : %d \n\n", st.name, st.roll_no, st.dsa, st.co, st.de);
    fclose(ptr);
}

int main()
{
    int chooseoption;
    char filename[] = "student.bin";
    while (1)
    {
        printf("Choose an option:\n1. Append new record of a student to the existing file.\n2. Delete a record of a specific student.\n3. Update a field of student.\n4. Display all records\n0. Exit\n : ");
        scanf("%d", &chooseoption);
        switch (chooseoption)
        {
        case 0:
            printf("exiting.....\n");
            exit(0);

        case 1:
            createrecords(filename);
            break;

        case 2:
            delete_update_record(filename, 0);
            break;

        case 3:
            delete_update_record(filename, 1);
            break;

        case 4:
            displayrecords(filename);
            break;

        default:
            printf("Please enter a valid option!!!\n");
            break;
        }
    }
    return 0;
}