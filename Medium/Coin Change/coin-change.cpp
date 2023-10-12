//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int coins[], int n, int sum, vector<vector<long long>>& dp) {
    if (sum == 0) return 1;
    if (n < 0 || sum < 0) return 0;
    if (dp[n][sum] != -1) return dp[n][sum];
    
    // Use the current coin or exclude it
    long long ways = solve(coins, n, sum - coins[n], dp) + solve(coins, n - 1, sum, dp);
    
    dp[n][sum] = ways;
    return ways;
}

long long int count(int coins[], int n, int sum) {
    vector<vector<long long>> dp(n, vector<long long>(sum + 1, -1));
    return solve(coins, n - 1, sum, dp);
}



};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends