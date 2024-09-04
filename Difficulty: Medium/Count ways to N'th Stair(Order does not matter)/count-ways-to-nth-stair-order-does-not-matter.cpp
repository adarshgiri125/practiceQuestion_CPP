//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    unordered_map<int,int> mp;
	    int solve(int n , int i, vector<int> &dp){
	        if(i >= n - 1){
	            return 1;
	        }
	        if(dp[i] != -1) return dp[i];
	        int val1 = solve(n, i + 1,dp);
	        int val2 = solve(n, i + 2,dp);
	        
	        return dp[i] = 1 + min(val1,val2);
	    }
		int nthStair(int n){
	
		   
		    vector<int> dp(n + 1 , -1);
		  
		    return solve(n,0,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends