//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(string str1, string str2, int i, int j, vector<vector<int>> &dp) {
    // Base cases
    if (i >= str1.size()) return str2.size() - j; // If str1 is fully traversed, we need to insert the remaining characters of str2
    if (j >= str2.size()) return str1.size() - i; // If str2 is fully traversed, we need to delete the remaining characters of str1
    
    if (dp[i][j] != -1) return dp[i][j];
    
    if (str1[i] == str2[j]) {
        // If characters match, no operation needed, move to the next characters in both strings
        return dp[i][j] = solve(str1, str2, i + 1, j + 1, dp);
    } else {
        // Calculate the costs of removing, inserting, and replacing
        int remove = 1 + solve(str1, str2, i + 1, j, dp); // Remove current character from str1
        int insert = 1 + solve(str1, str2, i, j + 1, dp); // Insert current character of str2 into str1
        int replace = 2 + solve(str1, str2, i + 1, j + 1, dp); // Replace current character of str1 with str2's character
        
        // Take the minimum of the three operations
        return dp[i][j] = min({remove, insert, replace});
    }
}

int minOperations(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Adjust dimensions to n+1 x m+1
    return solve(str1, str2, 0, 0, dp);
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