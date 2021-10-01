#include <stdio.h>
void movehyphen(char *str)
{
	int i=0;
	char result[100];
	int j;
	while(*(str+i) != '\0')
	{
		if(*(str+i) == '-')
		{
			for(j=i-1;j>=0;j--)
			{
				result[j+1] = result[j];
			}
			result[0] = '-';
		}
		else
		{
			result[i] = *(str+i);
		}
		i++;
	}
	result[i] = '\0';

	printf("Modified String : %s", result);
	printf("\n");
}
int main()
{
	printf("Move Hyphens of a String to Front\n");
	printf("*********************************\n\n");
	char str[100];
	printf("Enter String : ");
	scanf("%s",str);
	printf("\n");
	movehyphen(str);
}