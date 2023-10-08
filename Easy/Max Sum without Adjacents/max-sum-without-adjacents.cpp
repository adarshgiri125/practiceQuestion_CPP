//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
/// -------->>>>>>>> Memoization Recursion <<<<<----------
//     int solve(int *arr, int n,vector<int> &dp){
//         if(n == 0) return arr[n];
//         if(n < 0) return 0;
//         if(dp[n] != -1) return dp[n];
        
//         int first = arr[n] + solve(arr,n-2,dp);
//         int second = 0 + solve(arr,n-1,dp);
        
//         return dp[n] = max(first,second);
//     }
// 	// calculate the maximum sum with out adjacent
// 	int findMaxSum(int *arr, int n) {
// 	    // code here
// 	    vector<int> dp(n,-1);
// 	    return solve(arr,n-1,dp);
// 	}

   /// ----->>>>>> optimize approach with space optimize <<<-------
   
   int findMaxSum(int *arr, int n) {

	   int prev = arr[0];
	   int prev2 = 0;
	   
	   for(int i = 1; i<n; i++){
	       int first = arr[i];
	       if(i > 1) first += prev2;
	       
	       int second = 0 + prev;
	       
	       int value = max(first,second);
	       
	       prev2 = prev;
	       prev = value;
	   }
	   
	   return prev;
	}
   
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends