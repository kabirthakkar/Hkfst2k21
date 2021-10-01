#include <stdio.h>
void appendFunction(char *des, char *src, int pos)
{
	*(des+pos) = ' ';
	int j = pos+1;
	int i=0;
	while(*(src+i) != '\0')
	{
		*(des+j) = *(src+i);
		i++;
		j++;
	}
	*(des+j) = '\0';
}
int findEndPos(char *des)
{
	int i=0;
	while(*(des+i) != '\0')
	{
		i++;
	}
	return i;
}
int main()
{
	printf("Appending a String to Another String\n");
	printf("************************************\n\n");
	char src[100], des[100];
	printf("Enter Destination String : ");
	scanf("%[^\n]%*c",des);
	printf("Enter Source String      : ");
	scanf("%[^\n]%*c",src);
	printf("\n");

	int pos = findEndPos(des);
	appendFunction(des,src,pos);

	int i=0;
	while(des[i] != '\0')
	{
		printf("%c", des[i]);
		i++;
	}
	printf("\n");
	return 0;
}