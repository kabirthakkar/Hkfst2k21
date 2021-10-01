#include <stdio.h>
int length(char *b)
{
	int i=0;
	while(*(b+i) != '\0')
	{
		i++;
	}
	return i;
}
void pattern(char *a, char *b)
{
	int l = length(b);
	int i=0;
	int flag;
	while(*(a+i) != '\0')
	{
		int j=i;
		int flag=1;
		int k=0;
		while(k<l)
		{
			if(*(a+j) != *(b+k))
			{
				flag=0;
				break;
			}
			j++;
			k++;
		}
		if(flag==1)
		{
			printf("Pattern Found\n");
			break;
		}
		i++;
	}
	if(*(a+i) == '\0')
	{
		printf("Pattern not Found\n");
	}
}
int main()
{
	printf("Pattern Matching\n");
	printf("****************\n\n");
	char a[100], b[100];
	printf("Enter String : ");
	scanf("%[^\n]%*c",a);
	printf("\n");
	printf("Enter Pattern to be Searched : ");
	scanf("%[^\n]%*c",b);
	printf("\n");
	pattern(a,b);
	return 0; 
}