//Tower of Hanoi using Recursion

#include<iostream>
using namespace std;

int toh(int n,int a,int b,int c)
{
    if(n>0)
    {
    toh(n-1,a,c,b);
    cout<<a<<"to"<<c<<"\n";
    toh(n-1,b,a,c);
    }
}

int main()
{
    int n,a=1,b=2,c=3;
    cin>>n;
    
    toh(n,a,b,c);
    
    return 0;
}
