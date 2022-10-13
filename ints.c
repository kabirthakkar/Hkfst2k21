#include<stdio.h>
void main()
{
    int i,j,a[100],b[100],c[100],k=0,n,s;
    printf("Enter the size of the first array\n");
    scanf("%d",&n);
    printf("Enter the elements of the first array\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
     printf("Enter the size of the second array\n");
    scanf("%d",&s);
     printf("Enter the elements of the second array\n");
    for(i=0;i<s;i++)
    scanf("%d",&b[i]);
    if(n<s)
    {
    for(i=0;i<n;i++)
    {
        for(j=0;j<s;j++)
        {
         if(a[i]==b[j])
         {
         c[k]=a[i];
         k=k+1;
         }
        }
    }
    }
    if(s<n)
        {
    for(i=0;i<s;i++)
    {
        for(j=0;j<n;j++)
        {
         if(b[i]==a[j])
         {
         c[k]=b[i];
         k=k+1;
         }
        }
    }
    }
    printf("The intersected array is");
    for(i=0;i<k;i++)
    printf("%d ,",c[i]);
}