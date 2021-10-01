#include <stdio.h>
void compare(char *str1, char *str2, int l1, int l2)
{
	int same=0;
	if(l1 == l2)
	{
		int i=0;
		while(i<l1)
		{
			if(*(str1+i) != *(str2+i))
			{
				same = 1;
				break;
			}
			i++;
		}
		if(same==0)
		{
			printf("Strings are Equal\n");
		}
		else
		{
			if(*(str1+i) > *(str2+i))
			{
				printf("1st String is greater than 2nd String\n");
			}
			else
			{
				printf("2nd String is greater than 1st String\n");
			}
		}
	}
	else
	{
		printf("Strings are Not Equal\n");
	}
}
void findLength(char *str1, char *str2)
{
	int i=0,l1=0,l2=0;
	while(*(str1+i) != '\0')
	{
		l1 = l1 + 1;
		i++;
	}
	i=0;
	while(*(str2+i) != '\0')
	{
		l2 = l2 + 1;
		i++;
	}
	compare(str1,str2,l1,l2);
}
int main()
{
	printf("Comparing Two String\n");
	printf("********************\n\n");
	char str1[100], str2[100];
	printf("Enter 1st String : ");
	scanf("%[^\n]%*c",str1);
	printf("Enter 2nd String : ");
	scanf("%[^\n]%*c",str2);
	printf("\n");
	findLength(str1,str2);
	return 0;
}