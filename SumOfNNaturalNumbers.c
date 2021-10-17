#include<stdio.h>
int sum(int n)
{
	if(n==0)
	{
		return 0;
	}
	else
	{
		return sum(n-1)+n;
	}
}
int main()
{
int s;
s=sum(3);
printf("%d",s);
return 0;
}
