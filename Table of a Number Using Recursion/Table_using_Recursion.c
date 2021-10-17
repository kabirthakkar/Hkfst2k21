#include <stdio.h>
int table(int n, int i)
{
    printf("\n");
    printf("  %d * %d = %d", n, i, n * i);
    if (i >= 10)
    {
        return 0;
    }
    else
    {
        return table(n, i + 1);
    }
}
int main()
{
    int n, i = 1;
    printf("\n Enter a Number: ");
    scanf("%d", &n);
    table(n, i);
}
