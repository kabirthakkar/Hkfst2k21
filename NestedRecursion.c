#include<stdio.h>
//Nested Recursion - recursive function is passed as parameter inside a function.
int fun(int n)
{
if(n>100)
	return n-10;
return fun(fun(n+11));
}
int main()
{
	int r;
	r=fun(50);
	printf("%d\n",r);
	return 0;
}
