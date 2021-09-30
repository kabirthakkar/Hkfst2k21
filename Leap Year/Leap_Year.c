#include <stdio.h>
int main()
{
    int yr;
    printf("\n Enter a Year: ");
    scanf("%d", &yr);
    if ((yr % 400 == 0) || (yr % 100 != 0 && yr % 4 == 0))
        printf("\n %d is a Leap Year", yr);
    else
        printf("\n %d is not a Leap Year", yr);
}
