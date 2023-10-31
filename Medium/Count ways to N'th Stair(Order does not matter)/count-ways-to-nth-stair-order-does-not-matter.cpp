//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int f(int n, vector<int> &dp){
	        if(n == 0) return 1;
	        if(n == 1) return 1;
	        
	        if(dp[n] != -1) return dp[n];
	        
	        return dp[n] = 1 + min(f(n-1, dp), f(n-2, dp));
	    }
	    
		int nthStair(int n){
		    vector<int> dp(n+1, -1);
		    return f(n, dp);
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