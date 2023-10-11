//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod = 1e9 + 7;
    long long int solve(int m, int n,int i, int j,vector<vector<long long> > &dp){
      if( i < 0 || j < 0){
          return 0;
      }
      if(i == 0 && j == 0) {
       
          return 1;
      }
      if(dp[i][j] != -1) return dp[i][j];
      
      int up = (solve(m,n,i-1,j,dp)) % mod;
      int down = (solve(m,n,i,j-1,dp)) % mod;
      return dp[i][j] = (up + down) % mod;
      
    }
    long long int numberOfPaths(int m, int n){
        vector<vector<long long int> >dp(m,vector<long long int> (n,-1));
        solve(m,n,m-1,n-1,dp);
        return dp[m-1][n-1];
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends