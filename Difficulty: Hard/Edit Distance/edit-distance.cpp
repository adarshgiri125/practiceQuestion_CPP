//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(string word1, string word2, int i, int j, int m, int n, vector<vector<int> > &dp){
        if(i >= m) {
        return n - j;
    }
    if(j >= n) {
        return m - i;
    }
    if(dp[i][j] != -1) return dp[i][j];
        int del = 1e9;
        int rep = 1e9;
        int ins = 1e9;
        if(word1[i] == word2[j]){
            return solve(word1, word2, i+1, j+1, m,n,dp);
        }
        else{
            del = 1 + solve(word1,word2,i+1,j,m,n,dp);
            rep = 1 + solve(word1,word2, i+1, j+1, m,n,dp);
            ins = 1 + solve(word1, word2,i,j+1,m,n,dp);
        }
        int ans = min(del,min(rep,ins));
        return dp[i][j] = ans;

   }
    int editDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > dp(m,vector<int> (n,-1));
        return solve(word1, word2,0,0,m, n,dp);
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