#include <stdio.h>

int main()
{
    char name[14];
    printf("ENTER Single WORD: ");
    scanf("%s",&name);
    for(int i=0; i<14; i++)
        {
            while(name[i]>=65)
                {
                printf(" %d ", name[i]);
                break;
                }
        }
        return 0;


}
