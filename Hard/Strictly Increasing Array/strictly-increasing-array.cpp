//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   
    int solve(vector<int>& nums, int i, int picked,vector<vector<int>>& dp){
        if(i >= nums.size()){
            return 0;
        }
        
        if(dp[picked + 1][i] != -1) return dp[picked + 1][i];
        int ans1 = 0;
        if(picked == -1 || (nums[i] > nums[picked] && nums[i] - nums[picked] >= i - picked)){
            ans1 = 1 + solve(nums,i+1,i,dp);
        }
        
        int ans2 = solve(nums,i+1,picked,dp);
      
        
        return dp[picked + 1][i] = max(ans1,ans2);
        
    }

    int min_operations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int> (n + 1, -1));
        int lis = solve(nums,0,-1,dp);
        
        return (n - lis);
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends