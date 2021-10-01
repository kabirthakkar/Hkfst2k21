#include <stdio.h>
void insert(char *a, char *b, int pos, char *str)
{
	int i=0,j=0,k=0;
	while(*(a+i) != '\0')
	{
		if(i==pos)
		{
			while(*(b+k) != '\0')
			{
				*(str+j) = *(b+k);
				j++;
				k++;
			}
		}
		*(str+j) = *(a+i);
		j++;
		i++;
	}
}
int main()
{
	printf("Inserting a String into Main String\n");
	printf("***********************************\n\n");
	char a[100],b[100],newStr[100];
	int pos;
	printf("Enter Main String : ");
	scanf("%[^\n]%*c",a);
	printf("\n");
	printf("Enter the String to be Inserted : ");
	scanf("%[^\n]%*c",b);
	printf("Enter Position : ");
	scanf("%d",&pos);
	insert(a,b,pos,newStr);
	printf("New String : ");
	int i=0;
	while(newStr[i] != '\0')
	{
		printf("%c",newStr[i]);
		i++;
	}
	printf("\n");
	return 0; 
}