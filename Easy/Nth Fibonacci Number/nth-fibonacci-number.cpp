//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   
    int M = 1e9 + 7;
    long long int solve(vector<long long int> &dp,long long int n){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        
        dp[n] = solve(dp,n-1) + solve(dp,n-2);
        
        return dp[n] % M;
    }
    long long int nthFibonacci(long long int n){
       vector<long long int> dp(n+1, -1);
       return solve(dp,n);
    }
    
   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends