//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    // int solve(int n,vector<int> &dp){
    //     if ( n == 2) return 2;
    //     if (n == 1) return 1;
    //     if(dp[n] != -1) return dp[n];
        
    //     int left = 1;
    //     if(n % 2 == 0) left += solve(n/2,dp); 
    //     else left += 1 + solve(n/2,dp);
    //     int right = 1 + solve(n-1,dp);
        
    //     return dp[n] = min(left,right);
    // }
    // int minOperation(int n)
    // {
    //      vector<int> dp(n + 1, -1);
    //      return solve(n,dp);
       
    // }
    
   int minOperation(int n)
{
    vector<int> dp(n + 1);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        int left = 1; // Initialize left with a large value
        if (i % 2 == 0) {
            left += dp[i / 2]; // No extra operation needed for even numbers
        } else {
            left = INT_MAX;
        }

        int right = dp[i - 1] + 1;

        dp[i] = min(left, right);
    }

    return dp[n];
}




    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends