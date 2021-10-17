#include <stdio.h>
int main()
{
    char name[20], branch[10];
    int i, rollno, marks, n;
    FILE *p;
    p = fopen("stdntrcrd.txt", "w"); // Open file in Write mode...
    printf("\nEnter No. of Students: ");
    scanf("%d", &n);
    fflush(stdin);
    for (i = 1; i <= n; i++) // Input the records and save to file...
    {
        printf("\n\nEnter The Information of Student %d", i);
        printf("\n\nEnter Name: ");
        gets(name);
        fflush(stdin);
        printf("Enter Branch: ");
        gets(branch);
        fflush(stdin);
        printf("Enter Roll No.: ");
        scanf("%d", &rollno);
        printf("Enter The Marks: ");
        scanf("%d", &marks);
        fflush(stdin);
        fprintf(p, "%s\t%s\t%d\t%d", name, branch, rollno, marks);
    }
    fclose(p);
    // Display the Records from the file in notepad...
    printf("\nData read from the file... \n");
    p = fopen("stdntrcrd.txt", "r");
    while (!feof(p))
    {
        fscanf(p, "%s\t%s\t%d\t%d", name, branch, &rollno, &marks);
        fprintf(stdout, "\n%s\t%s\t%d\t%d", name, branch, rollno, marks);
    }
}
