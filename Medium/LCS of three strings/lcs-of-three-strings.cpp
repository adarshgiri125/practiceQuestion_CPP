//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

        int lcs(string A,string B,string C,int i,int j,int k,vector<vector<vector<int>>> &dp) {
        if(i==0 or j==0 or k==0) return 0;
        
        if(A[i-1]==B[j-1] and B[j-1]==C[k-1]) {
            return dp[i][j][k]=1+lcs(A,B,C,i-1,j-1,k-1,dp);
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        int l=lcs(A,B,C,i-1,j,k,dp);
        int m=lcs(A,B,C,i,j-1,k,dp);
        int n=lcs(A,B,C,i,j,k-1,dp);
        return dp[i][j][k]=max(l,max(m,n));
    }
    public:

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
            return lcs(A,B,C,n1,n2,n3,dp);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends