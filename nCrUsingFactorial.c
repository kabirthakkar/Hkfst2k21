#include<stdio.h>
double fact(double n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		return fact(n-1)*n;
	}
}
double nCr(double n,double r)
{
	return fact(n)/(fact(n-r)*fact(r));
}
int main()
{

printf("%.0lf",nCr(3,2));
return 0;
}
