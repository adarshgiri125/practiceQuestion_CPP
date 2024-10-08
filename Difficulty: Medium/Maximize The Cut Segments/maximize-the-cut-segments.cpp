//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n, int x, int y, int z,vector<int> &dp){
        if(n == 0) return 1;
        if(n < 0) return -1e8;
        if(dp[n] != -1) return dp[n];
        int value = 1 + solve(n-x,x,y,z,dp);
        int value2 = 1 + solve(n-y,x,y,z,dp);
        int value3 = 1 + solve(n-z,x,y,z,dp);
        
        int ans = max({value,value2,value3});
        return dp[n] = ans;
        
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // vector<int> dp(n+1,-1);
        // int result = solve(n,x,y,z,dp);
        // if(result < 0) return 0;
        // return result - 1;
        vector<int> dp(n+1, INT_MIN);
        dp[0] = 0;
        
        for(int i = 1; i<=n; i++){
            if(i - x >= 0)  dp[i] = max(dp[i],dp[i-x]+1);
            if(i - y >= 0)  dp[i] = max(dp[i],dp[i-y]+1);
            if(i - z >= 0)  dp[i] = max(dp[i],dp[i-z]+1);
        }
        if(dp[n] < 0) 
            return 0;
        else 
            return dp[n];
        
        
    }
};


//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends