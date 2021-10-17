#include <stdio.h>
int main()
{
    char a[150];
    int i, j;
    printf("\n Enter a String: ");
    gets(a);
    for (i = 0; a[i] != '\0'; i++)
    {
        while (!((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')))
        {
            for (j = i; a[j] != '\0'; j++)
            {
                a[j] = a[j + 1];
            }
            a[j] = '\0';
            i--;
        }
    }
    printf("\n Output String: ");
    puts(a);
}
