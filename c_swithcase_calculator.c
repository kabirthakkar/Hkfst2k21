#include<stdio.h>

int main()
{
    char operator;
    float number1, number2;

    printf("Enter calculation: ");
    scanf("%f %c %f", &number1, &operator, &number2);

    switch(operator)
    {
        case '+': printf("%.2f ",number1+number2);
                break;

        case '-': printf("%.2f ",number1-number2);
                break; 

        case '*': printf("%.2f ",number1*number2);
                break; 

        case '/': printf("%.2f ",number1/number2);
                break; 

        default: printf("Invalid operator!"); 
    }
    
}