//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int solve(int i, int j , string & a, string & b,vector<vector<int>> & dp){
        
        //we have to add the remaning string : 
        if (i>=a.size()){
            return b.size()-j;
        }
        
        //might be string b is smaller then string a to do that we need to remove all 
        // the reming charecter of string a :
        if (j>=b.size()){
            return a.size()-i;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        int equal = 0, dlt = 0, Insert = 0 , Replace_char_from_string_b = 0;
        if (a[i]==b[j]){
            equal = solve(i+1,j+1,a,b,dp);
            return dp[i][j] = equal;//if you don't return here the value will not be 
            //updated in other operation delet, insert, replace;  
        }
        else{
            dlt =1 + solve(i+1,j, a,b,dp);
            Insert = 1 + solve(i,j+1,a,b,dp);//assuming we inserted an correct charecter
            Replace_char_from_string_b = 1 + solve(i+1,j+1,a,b,dp);
        }
        return dp[i][j] = min(dlt,min(Insert,Replace_char_from_string_b));
    }
    int editDistance(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,dp);
    }


};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends