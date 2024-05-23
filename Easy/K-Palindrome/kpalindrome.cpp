//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(string &a, string &b,int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        dp[n][n]=0;
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(a[i]==b[j]) dp[i][j] = 1+dp[i+1][j+1];
                else dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
    
    int kPalindrome(string str, int n, int k){
        string b = str;
        reverse(b.begin(),b.end());
        int x = solve(str,b,n);
        return (x+k>=n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends