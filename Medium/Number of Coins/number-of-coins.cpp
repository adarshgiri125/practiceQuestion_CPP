//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:

    
    int solve(int coins[], int m, int v, vector<vector<int> > &dp) {
        // Base cases
        if (v == 0) return 0;
        if (v < 0 || m < 0) return INT_MAX - 1;
        if (dp[m][v] != -1) return dp[m][v];
    
        
        int useCoin = 1 + solve(coins, m, v - coins[m], dp);
        int skipCoin = solve(coins, m - 1, v, dp);
    
        int ans = min(useCoin, skipCoin);
    
        return dp[m][v] = ans;
    }
    
    int minCoins(int coins[], int m, int v) {
        vector<vector<int> > dp(m, vector<int>(v + 1, -1));
        sort(coins, coins + m);
        int result = solve(coins, m - 1, v, dp);
    
        return (result >= INT_MAX - 1) ? -1 : result;
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