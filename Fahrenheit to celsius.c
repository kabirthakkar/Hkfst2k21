#include<stdio.h>
int main()
{
	float c,f;
	printf("Convert temperature in fahrenheit to celsius");
	printf("\nenter the value of temperature in fahrenheit=");
	scanf("%f",&f);
	c=5.0/9.0*(f-32);
	printf("temperature in celsius is %f",c);
	return 0;
}
