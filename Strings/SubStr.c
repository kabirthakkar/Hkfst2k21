#include <stdio.h>
void displaySub(char *sub)
{
	printf("Substring : ");
	int i=0;
	while(*(sub+i) != '\0')
	{
		printf("%c",*(sub+i));
		i++;
	}
	printf("\n");
}
void extractSub(char *str, int start, int end)
{
	char substr[100];
	int i=0;
	while(start < end)
	{
		substr[i] = *(str+start);
		start++;
		i++;
	}
	substr[i] = '\0';
	displaySub(substr);
}
int main()
{
	printf("Extract a Substring from a String\n");
	printf("*********************************\n\n");
	char string[100];
	int startPos,endPos;
	printf("Enter String : ");
	scanf("%[^\n]%*c",string);
	printf("\n");
	printf("Enter Starting Position : ");
	scanf("%d",&startPos);
	while(1)
	{
		printf("Enter Ending Position   : ");
		scanf("%d",&endPos);
		if(endPos > startPos)
		{
			break;
		}
	}
	printf("\n");
	extractSub(string,startPos,endPos);
	return 0;
}