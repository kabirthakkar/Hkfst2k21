#include<stdio.h>
#include<stdbool.h>

int binarysearch(int a[],int n,int k,bool searchfirst){
    int result=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==k)  {
              result=mid;
           if(searchfirst)
              high=mid-1;
            else
              low=mid+1;
    }
    else if(k<a[mid])  high=mid-1;
    else low=mid+1;
    }
    return result;
}
void sorting(int a[],int n)
{
    int i,j,temp;
    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
            while ( j > 0 && a[j-1] > a[j])
            {
                temp     = a[j];
                a[j]   = a[j-1];
                a[j-1] = temp;
                j--;
            }
    }
}
void display(int a[],int size)
    {
         printf("\n \n \t Displaying entered array.. ");
        for(int k=0;k<size;k++)
        {
            printf(" %d ",a[k]);
        }
    }
int main(){
    int size,key;
    printf("\n Enter the number of elements for an array:> \t");
    scanf("%d",&size);
    int a[size];
    printf("\n enter the %d elements in the array.\n",size);
    for(int i=0;i<size;i++)
    {
        printf("\nelement %d:- ",i+1);
        scanf("%d",&a[i]);

    }
    display(a,size);

     sorting(a,size);
     printf("\n \t After sorting array ..");
     display(a,size);
    int n=sizeof(a)/sizeof(a[0]);
    int x;
    printf("\n Enter the  key  element:\t");
    scanf("%d",&x);
    int f=binarysearch(a,n,x,true);
    printf("first occurence at %d index \n",f);
    if(f==-1){
        printf("elment not found in the array:\n ");
    }
    else {
        int l=binarysearch(a,n,x,false);
        printf("last occurence at %d index\n",l);
        printf("count is = %d", l-f+1);
    }

}
