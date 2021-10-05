// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

/*

Question: Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the 
amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only 
(right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the 
right or right or diagonally down towards the right. Find out maximum amount of gold he can collect.

Solution:

so u can move right, right-up, right-down.

if u r in cell [i][j] then
right -> [i][j+1]
right-up -> [i-1][j+1]
right-down -> [i+1][j+1]

but for last col we wont have right/right-up/right-down
and for first row we wont have right-up
and for last row we wont have right-down.

come from last col to 1st col. so last col remains as it is. from last 2nd col working starts. 
so in dp table we have to give same matrix values for last col.

so u can do this in 2 ways:

WAY-1:
1. add 1 row top + 1 row bottom + 1 row right.
2. so dp table size will be rows+2 x cols+1
3. and as last col will have same values as matrix we have to put those values in 
for(int i=1;i<=row;i++)
{
    dp[i][col-1]=M[i-1][col-1];
}
initialize all other cells with INT_MIN (useful for comparison)

WAY-2:
1. dp -> nxm
2. right will not be there when column = last column.
3. right-up will not be there for 1st row + last col.
4. right-down will not be there for last row + last col.

restrict like this.


and from all those 3 values take the maximum one. 
at the end in the first col u will get the result.
*/

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        
        int dp[n+2][m+1];
        for(int j=m;j>=0;j--) // cols
        {
            for(int i=0;i<n+2;i++)
            {
                if(j==m-1 && i>0 && i<n+1)
                {
                    dp[i][j]=M[i-1][j];
                }
                else
                {
                    dp[i][j] = INT_MIN;
                }
            }
        }
        
        // for(int i=0;i<n+2;i++)
        // {
        //     for(int j=0;j<m+1;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        // cout<<"\n";
        // dp = n+2 x m+1
        
        for(int j=m-2;j>=0;j--) // cols
        {
            for(int i=1;i<=n;i++) // rows
            {

                // case -1 i==0 no up right
                if(i==1)
                    dp[i][j] = M[i-1][j] + max(dp[i][j+1], dp[i+1][j+1]);
                // case - 2 i==n-1 no bottom right
                else if(i==n)
                    dp[i][j] = M[i-1][j] + max({dp[i-1][j+1], dp[i][j+1]});
                // case 3 .. others
                else
                    dp[i][j] =  M[i-1][j] + max({dp[i-1][j+1], dp[i][j+1], dp[i+1][j+1]});
                    
                //cout<<" i="<<i<<" j="<<j<<" dp[i][j]="<<dp[i][j]<<" ";
            }
           // cout<<"\n";
        }
        int maxx=0;
        
        for(int i=1;i<=n;i++)
        {
            if(dp[i][0]>maxx)
                maxx=dp[i][0];
        }
        
        return maxx;
        
        /*int dp[n][m]; // n-rows, m-cols
        memset(dp, 0, sizeof(dp));
        
        for(int j=m-1;j>=0;j--) // cols
        {
            for(int i=0;i<n;i++) // row
            {
                int right = (j==m-1)?0:dp[i][j+1]; // last col value.
                int right_up = (i==0 || j==m-1)?0:dp[i-1][j+1]; // first row & last col 
                int right_down = (i==n-1 || j==m-1)?0:dp[i+1][j+1]; // last row & last col.
                
                dp[i][j] = M[i][j] + max({right, right_up, right_down});
            }
        }
        
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i][0]>maxx)
                maxx=dp[i][0];
        }
        
        return maxx;*/
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends