//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    int solve(int ind, int d,vector<int> &arr,int sum, vector<vector<int> > &dp){
        if(ind < 0){
            if(sum==0) return 1;
            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int notpick = solve(ind-1,d,arr,sum,dp);
        int pick = 0;
        if(arr[ind] <= sum) pick = solve(ind-1,d,arr,sum-arr[ind],dp);
        
        return dp[ind][sum] = (notpick + pick) % mod;
        
    }
    int countPartitions(int n, int d, vector<int>& arr){
        
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        int target = (sum - d) / 2;
        if(((sum - d) < 0 ) || ((sum - d) % 2 != 0)){
            return 0;
        }
        vector<vector<int> > dp(n,vector<int> (target+1, -1));
        return solve(n-1,d,arr,(sum - d) / 2,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends