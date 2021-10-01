#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the length of array :";
    cin>>n;

    char arr[n];
    cout<<"Enter your array :";
    cin>>arr;

    bool check =1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != arr[n-1-i]){
            check=0;
        }
    }

    if (check){
        cout<<arr<<" is a pallindrome"<<endl;}
    else{
        cout<<arr<<" is not a pallindrome"<<endl;}

}