#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        if(n<=0)return 0;
        int maxSum = arr[0];
        int currSum = arr[0];
        
        for(int i=1;i<n;i++){
            if(currSum+arr[i]>arr[i]){
                currSum+=arr[i];
            }
            else{
                currSum = arr[i];
            }
            
            maxSum = max(maxSum,currSum);
        }
        
        return maxSum;
        
        

}

int main(){
    int arr[] = {1,2,3,-2,5};
    int n = 5;
    cout<<maxSubarraySum(arr,n)<<endl;
    int arr1[] = {-1,-2,-3,-4};
    int n1=4;
    cout<<maxSubarraySum(arr1,n1)<<endl;
    
}

