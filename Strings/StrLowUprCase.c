#include <stdio.h>
void toLowerCase(char *str)
{
	int i=0;
	char ch;
	while(*(str+i) != '\0')
	{
		ch = *(str+i);
		if((int)ch >=97 && (int)ch <= 122)
		{
			//Do Nothing
		}
		else if((int)ch == 32) //ASCII Code of Blank Space
		{
			//Do Nothing
		}
		else
		{
			*(str+i) = *(str+i) + 32;
		}
		i++;
	}
}
void toUpperCase(char *str)
{
	int i=0;
	char ch;
	while(*(str+i) != '\0')
	{
		ch = *(str+i);
		if((int)ch >=65 && (int)ch <= 90)
		{
			//Do Nothing
		}
		else if((int)ch == 32) //ASCII Code of Blank Space
		{
			//Do Nothing
		}
		else
		{
			*(str+i) = *(str+i) - 32;
		}
		i++;
	}
}
int main()
{
	// ASCII Codes
	// printf("%d", (int)'A'); ---> 65
	// printf("%d", (int)'Z'); ---> 90
	// printf("%d", (int)'a'); ---> 97
	// printf("%d", (int)'z'); ---> 122
	printf("String to Uppercase or Lowercase\n");
	printf("********************************\n\n");
	int choice;
	char string[100];
	printf("Enter String : ");
	scanf("%[^\n]%*c", string);
	printf("\n");
	printf("1 : Lowercase\n2 : UpperCase\n\n");
	while(1)
	{
		printf("Enter Choice : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\n");
			toLowerCase(string);
			break;
		}
		else if(choice==2)
		{
			printf("\n");
			toUpperCase(string);
			break;
		}
	}
	printf("Converted String : ");
	int i=0;
	while(string[i] != '\0')
	{
		printf("%c", string[i]);
		i++;
	}
	printf("\n");
	return 0;
}