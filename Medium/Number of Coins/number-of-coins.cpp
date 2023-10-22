//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:

    
    int solve(int coins[], int m, int v, vector<vector<int> > &dp) {
        // Base cases
        if (v == 0) return 0;
        if (v < 0 || m < 0) return INT_MAX-1;
        if (dp[m][v] != -1) return dp[m][v];
    
        
        int useCoin = 1 + solve(coins, m, v - coins[m], dp);
        int skipCoin = solve(coins, m - 1, v, dp);
    
        int ans = min(useCoin, skipCoin);
    
        return dp[m][v] = ans;
    }
    
    int minCoins(int coins[], int n, int val) {
        vector<vector<int> > dp(n, vector<int>(val + 1, -1));
        // sort(coins, coins + m);
        // int result = solve(coins, m - 1, v, dp);
    
        // return (result >= INT_MAX - 1) ? -1 : result;
        for(int i = 0; i<n; i++) dp[i][0] = 0;
        for(int m = 1; m < n; m++){
            for(int v = 0; v<= val; v++){
                
                int useCoin = 1e9;
                if( v - coins[m] >= 0) useCoin = 1 + solve(coins, m, v - coins[m], dp);
                int skipCoin = 1e9;
                if(m - 1 >= 0) skipCoin = solve(coins, m - 1, v, dp);
                int ans = min(useCoin, skipCoin);
                
                dp[m][v] = ans;
                
            }
        }
        if(dp[n-1][val] >= 1e9) return -1;
        return dp[n-1][val];
    }

	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends