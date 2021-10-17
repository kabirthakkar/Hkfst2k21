#include<stdio.h>
int fun(int n)
{
	if(n>0)
	{
		return fun(n-1)+n;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int r;
	r=fun(5);
	printf("%d",r);
	return 0;
}
