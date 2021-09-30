#include<stdio.h>
int main()
{
	int x1,x2,y1,y2,y,x;
	float m,c;
	printf("To find the equation of straight line passing through 2 points");
	printf("\nenter the values of x1,x2,y1,y2 respectively");
	scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
	m=(y2-y1)*1.0/(x2-x1);
	c=y1-(m*x1);
	printf("\nthe equation of line is y=%fx+%f",m,c);
	return 0;
}
