//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int> &arr, int sum,int ind, vector<vector<int> > &dp){
        if(sum == 0) return true;
        if(ind == 0) return (arr[0] == sum);
        if(dp[ind][sum] != -1) return dp[ind][sum];
        bool not_take = solve(arr,sum,ind-1,dp);
        bool take = false;
        if(arr[ind] <= sum) take = solve(arr,sum - arr[ind],ind-1,dp);
        
        return dp[ind][sum] = take || not_take;
    }
    
    bool isSubsetSum(vector<int> arr, int sum) {
      int n = arr.size();
      vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
            
        }
        if(arr[0] <= sum) dp[0][arr[0]] = true;
         
    
        for (int ind = 1; ind < n; ind++) {
            for(int target = 1; target <= sum; target++) {
                bool not_take = dp[ind - 1][target];
                bool take = false;
                if(arr[ind] <= target){
                     take = dp[ind - 1][target - arr[ind]];
                }
                
                dp[ind][target] = not_take || take;
            }
         
        }

        return dp[n - 1][sum];
   }

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends