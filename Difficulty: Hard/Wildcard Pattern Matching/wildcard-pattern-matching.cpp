//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int solve(string pattern, string str, int ind,int ind2, vector<vector<int> > &dp){\
        if(ind >= pattern.size() && ind2 >= str.size()) return 1;
        if(ind >= pattern.size()) return 0;
        
        if (ind2 >= str.size()) {
       
        while (ind < pattern.size()) {
            if (pattern[ind] != '*') return 0;
            ind++;
        }
        return 1;
    }
        
        if(dp[ind][ind2] != -1) return dp[ind][ind2];
        bool solve2 = 0;
        if(pattern[ind] == str[ind2] || pattern[ind] == '?'){
            return dp[ind][ind2] = solve(pattern,str,ind + 1, ind2 + 1,dp);
        }
        else if(pattern[ind] == '*'){
            return dp[ind][ind2]  = (solve(pattern,str,ind+1,ind2,dp) || solve(pattern,str,ind,ind2 + 1,dp));
        }
        return dp[ind][ind2] = 0;
        
    }
    int wildCard(string pattern, string str) {
        vector<vector<int> > dp(pattern.size() + 1, vector<int> (str.size() + 1, -1));
        return solve(pattern,str,0,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends