=
#include<stdio.h>


void funloop(int n)
{
	while(n>0)
	{
		print("%d ",n);
		n--;
	}
}
int main()
{
	int n=5;
	funrec(n);
		
	return 0;
}
