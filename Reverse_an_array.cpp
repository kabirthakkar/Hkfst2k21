#include<iostream>
using namespace std;

void arrRev(int arr[], int n){

 int temp = 0;

 for(int i =0; i<n/2 ; i++){
    temp = arr[i];
    arr[i] = arr[(n-1)-i];
    arr[(n-1)-i] = temp;

 }
}

void arrPrint(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, i;
    cout<<"Enter the length of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for(i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Before swapping, the array was : ";
    arrPrint(arr, n);

    arrRev(arr, n);


    cout<<"After swapping, the array is : ";
    
    arrPrint(arr, n);

    return 0;
}