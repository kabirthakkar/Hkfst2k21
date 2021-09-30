#include<stdio.h>
int main()
{
	float area,r,circumference;
	printf("To find the area and circumference of circle");
	printf("\nenter the value of radius=");
	scanf("%f",&r);
	area=22.0/7*r*r;
	circumference=2*22.0/7*r;
	printf("\ncircumference of circle is %f",circumference);
	printf("\nArea of the circle is %f",area);
}
