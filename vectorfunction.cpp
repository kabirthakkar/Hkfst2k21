#include<vector>
#include<iostream>
using namespace std;

main()
{   
    int n ,k,x;
    cout<<"enter array size , value and K ";
    cin>>n;
    vector <int> v ;
    for(int i=0;i<n;i++)
    {   cin>>x;
        v.push_back(x);
    }

    cin>>k;

    vector<int> v2;

    for(int i:v)
    {
        if(i<k)
        v2.push_back(i);
    }

    for(int j:v2)
    cout<<j<<" ";



    return 0;
}