//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        vector<vector<int > > dp(m+1, vector<int> (n+1, 0));
        
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(x[i-1] == y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return m + n - dp[m][n];
    //     int a = m;
    //     int b = n;
    //     string ans = "";
    //     while(a > 0 && b >= 0){
    //         if(x[a-1] == y[b-1]){
    //             ans += x[a-1];
    //             a--, b--;
    //         }
    //         else if(dp[a - 1][b] > dp[a][b-1]){
    //             ans += x[a-1];
    //             a--;
    //         }
    //         else{
    //             ans += y[b-1];
    //             b--;
    //         }
    //     }
    //     while(a > 0){
    //          ans += x[a-1];
    //          a--;
    //     }
    //     while(b > 0){
    //          ans += y[b-1];
    //          b--;
    //     }
        
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    }
};


//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends