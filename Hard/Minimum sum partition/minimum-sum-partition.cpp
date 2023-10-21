//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    
    int solve(int arr[], int n, int sum, int ind, int total, vector<vector<int> > &dp) {
        if (ind == 0) {
            return abs(total - 2 * sum);
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int take = solve(arr, n, sum + arr[ind], ind - 1, total,dp);
        int nottake = solve(arr, n, sum, ind - 1, total,dp);
    
        return dp[ind][sum] = min(take, nottake);
    }
    
    int minDifference(int arr[], int n) {
        int sum = 0;
    
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        vector<vector<int> > dp(n, vector<int> (sum+1, -1));
        int ans = INT_MAX;
        return solve(arr, n, 0, n - 1, sum,dp);
    }


};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends