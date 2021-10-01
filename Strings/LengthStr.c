#include <stdio.h>
int findLength(char *str)
{
	int i=0;
	while(*(str+i) != '\0')
	{
		i = i + 1;
	}
	return i;
}
int main()
{
	printf("Length of String\n");
	printf("****************\n\n");
	char string[100];
	printf("Enter String : ");
	scanf("%[^\n]%*c",string);
	printf("\n");
	int l = findLength(string);
	printf("Length of String : %d\n",l);
	return 0;
}