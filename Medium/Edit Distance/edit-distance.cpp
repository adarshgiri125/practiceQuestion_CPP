//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string &s, string &t, int i, int j,vector<vector<int> > &dp){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == t[j-1]){
            return dp[i][j] = solve(s,t,i-1,j-1,dp);
        }
        else {
            return dp[i][j] = 1 + min(solve(s,t,i,j-1,dp),
                     min(solve(s,t,i-1,j,dp),
                     solve(s,t,i-1,j-1,dp)));
        }  
    }
    int editDistance(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        vector<vector<int> > dp(n+1, vector<int> (m+1, -1));
        return solve(s,t,n,m,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends