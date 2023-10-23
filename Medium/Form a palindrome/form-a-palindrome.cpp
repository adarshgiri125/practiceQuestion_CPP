//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int LCS(string a, string b, int i, int j , vector<vector<int> > &dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i - 1] == b[j - 1]) return dp[i][j] =  1 + LCS(a,b, i-1, j - 1, dp);
        
        return dp[i][j] = max(LCS(a,b,i-1,j,dp), LCS(a,b,i,j-1,dp));
    }
    int findMinInsertions(string a){
       
        string b = a;
        reverse(a.begin(), a.end());
        int n = a.length();
        int m = b.length();
        vector<vector<int> > dp(n+1, vector<int> (m+1, -1));
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        for(int j = 0; j<=m; j++) dp[0][j] = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<= m; j++){
                if(a[i - 1] == b[j - 1]) dp[i][j] =  1 + dp[i-1][j - 1];
        
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return a.length() - dp[n][m];
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends