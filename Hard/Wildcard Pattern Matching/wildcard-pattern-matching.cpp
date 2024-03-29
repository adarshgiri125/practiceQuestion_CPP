//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int solve(int i, int j, string &pattern, string &str,vector<vector<int> > &dp){
       if(i < 0 && j < 0) return 1;
       if(i < 0 && j >= 0) return 0;
       if(i >= 0 && j < 0){
           for(int ii= 0; ii<=i; ii++){
               if(pattern[ii] != '*') return 0;
           }
           return 1;
       }
       if(dp[i][j] != -1) return dp[i][j];
        
       if(pattern[i] == str[j] || pattern[i] == '?'){
           return dp[i][j] = solve(i-1,j-1,pattern, str,dp);
       }
       if(pattern[i] == '*'){
           return dp[i][j] = (solve(i-1,j,pattern,str,dp) || solve(i,j-1,pattern,str,dp));
       }
       
       return 0;
       
    }
    int wildCard(string pattern,string str)
    {
        int n = pattern.length();
        int m = str.length();
        vector<vector<int> > dp(n+1, vector<int> (m+1, -1));
        return solve(n-1,m-1,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends