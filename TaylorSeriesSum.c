//Sum of Taylor Series Program
#include<stdio.h>

#include<math.h>

int main()
{
  int a;
    int factorial = 1,n;
    float sum=0;
    printf("\n\nEnter the value of a in the series :  ");
    scanf("%d",&a);

    printf("\nEnter the number of terms in the series  :   ");
    scanf("%d",&n);

    for(int i=1;i<n;i++)
    {
        factorial = factorial*i;
        sum = sum + (pow(a,i)/factorial) ;

    }
    sum= sum +1; 

    printf("\nThe sum of the taylor series is :  %.2f\n",sum);

    
    return 0;
}
