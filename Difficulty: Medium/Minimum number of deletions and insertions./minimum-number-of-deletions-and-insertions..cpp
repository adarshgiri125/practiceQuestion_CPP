//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(string str1, string str2, int i, int j, vector<vector<int>> &dp) {
    // Base cases
    if (i >= str1.size()) return str2.size() - j;
    if (j >= str2.size()) return str1.size() - i; 
    
    if (dp[i][j] != -1) return dp[i][j];
    
    if (str1[i] == str2[j]) {
       
        return dp[i][j] = solve(str1, str2, i + 1, j + 1, dp);
    } else {
       
        int remove = 1 + solve(str1, str2, i + 1, j, dp); 
        int insert = 1 + solve(str1, str2, i, j + 1, dp); 
        int replace = 2 + solve(str1, str2, i + 1, j + 1, dp);
      
        return dp[i][j] = min({remove, insert, replace});
    }
}

int minOperations(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); 

    
    for (int j = 0; j <= m; j++) {
        dp[n][j] = m - j;
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i][m] = n - i;
    }

   
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i + 1][j + 1]; 
            } else {
                int remove = 1 + dp[i + 1][j];
                int insert = 1 + dp[i][j + 1]; 
                int replace = 2 + dp[i + 1][j + 1]; 
                dp[i][j] = min({remove, insert, replace});
            }
        }
    }

   
    return dp[0][0];
}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends