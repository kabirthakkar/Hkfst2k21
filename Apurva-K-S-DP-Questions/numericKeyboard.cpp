// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    long long dp[10][30];
    int M[4][3] = {
                    {1,2,3},
                    {4,5,6},
                    {7,8,9},
                    {-1,0,-1}
                    };

	public:
	
	long long solve(int i, int j, int n)
	{
	    if(n==1) return 1; 
	    if(dp[M[i][j]][n]!=-1) return dp[M[i][j]][n]; // if the value is memoized, return it.
	    
	    long long self = solve(i, j, n-1); 
        // n=2 [00, 11, 22, etc etc] - are also counted. 
        // when we are at i, j position so we will pass i, j also. but with n-1 length.
	    
	    long long left=0,right=0,up=0,down=0;
	    
	    if(j-1>=0 && M[i][j-1]!=-1) left = solve(i, j-1, n-1); // check j-1>=0 bcoz for 0/4/7 we dont have left side values we cant go there. to ensure that this check is needed.
        // also if we are at 0, its left is -1 . we cant iterate through it. so M[i][j-1]!=-1 check
	    if(j+1<3 && M[i][j+1]!=-1) right = solve(i, j+1, n-1); // for 3/6/9 -> no right side j+1<3 check
        // for 0 right side = # (cant go there) so M[i][j+1]!=-1 check.
	    if(i-1>=0 && M[i-1][j]!=-1) up = solve(i-1, j, n-1); // for 1/2/3 no up -> i-1>=0 check.
        //  M[i-1][j]!=-1 == not needed here. u can remove it.
	    if(i+1<4 && M[i+1][j]!=-1) down = solve(i+1, j, n-1); // for 0 -> no down.
        // for 7/9 - bottom one is -1 so M[i+1][j] check 

        // with each move we decrement the length by 1.
	    
	    dp[M[i][j]][n] = self+left+right+up+down; // for any number we have to add the results obtained from self, right, left, up, down
	    
	    return dp[M[i][j]][n]; // return it.
	    
	}
	
	
	long long getCount(int N)
	{
		// Your code goes here
		dp[10][N+1];
		memset(dp, -1, sizeof(dp));
		long long ans=0;
		for(int i=0;i<4;i++) // iterating through each and every element of the keyboard
		{
		    for(int j=0;j<3;j++)
		    {
		        if(M[i][j]!=-1) // except # and $. so they are replaced by -1 in matrix.
		            ans+=solve(i,j,N); // add the result for each number.
		    }
		}
		
		return ans;
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
	    Solution ob;
	    cout << ob.getCount(n) << "\n";
    }
    return 0;
}
  // } Driver Code Ends