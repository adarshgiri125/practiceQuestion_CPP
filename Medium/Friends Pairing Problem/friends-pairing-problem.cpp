//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

 const int N = 1e5;
 
class Solution
{
public:
    long long int MM = 1000000007;
    long long dp[N];
    int solve(int n){
        if(n == 1 || n == 2){
            return n;
        }
        if(dp[n] != -1) return dp[n];
        
        dp[n] = ((solve(n-1))%MM + (n-1)*((solve(n-2))%MM))%MM;
        return dp[n];
    }
    int countFriendsPairings(int n) 
    { 
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends