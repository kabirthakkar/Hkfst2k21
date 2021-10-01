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
void reverse(char *str, int l)
{
	int end = l - 1;
	int start = 0;
	char temp;
	while(start <= end)
	{
		temp = *(str+start);
		*(str+start) = *(str+end);
		*(str+end) = temp;
		start++;
		end--;
	}
}
int main()
{
	printf("Reversing a String\n");
	printf("******************\n\n");
	char string[100];
	printf("Enter a String : ");
	scanf("%[^\n]%*c",string);
	printf("\n");
	int length = findLength(string);
	reverse(string, length);
	printf("After Reversing : ");
	int i=0;
	while(string[i] != '\0')
	{
		printf("%c\n",string[i]);
		i++;
	}
}