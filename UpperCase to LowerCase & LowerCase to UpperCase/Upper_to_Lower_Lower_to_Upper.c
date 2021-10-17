#include <stdio.h>
#include <string.h>
int main()
{
    char a[20];
    int i = 0, l, j;
    printf("\n Enter a String: ");
    scanf("%[^\n]s", &a);
    l = strlen(a);
    for (i = 0; i < l; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = a[i] - 32;
        }
        else if (a[i] == ' ')
            continue;
        else
            a[i] = a[i] + 32;
    }
    a[i + 1] = '\0';
    for (i = 0; a[i] != '\0'; i++)
    {
        printf("%c", a[i]);
    }
}
