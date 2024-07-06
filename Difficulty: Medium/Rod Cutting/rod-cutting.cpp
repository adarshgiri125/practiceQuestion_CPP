//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int price[], int n, int dp[]) {

    if (n == 0) return 0;
    
   
    if (dp[n] != -1) return dp[n];
    
    
    int ans = INT_MIN;
    
    // Try every possible cut length from 1 to n
    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, price[i-1] + solve(price, n - i, dp));
    }
    
    // Store the computed result in dp array
    dp[n] = ans;
    return ans;
}

int cutRod(int price[], int n) {
    // Initialize dp array with -1 (to indicate uncomputed states)
    int dp[n + 1];
    std::fill(dp, dp + n + 1, -1);
    return solve(price, n, dp);
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends