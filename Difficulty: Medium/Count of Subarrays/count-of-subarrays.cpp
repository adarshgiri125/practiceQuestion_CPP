//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    
	    ll ans = 0;
	    int prev = -1;
	    for(int i = 0; i<n; i++){
	        if(arr[i] > k){
	            ans++;
	            
	            ll left = i - (prev + 1);
	            ll right = n - i - 1;
	            ll ele = left * right;
	            
	            ans += left;
	            ans += right;
	            ans += ele;
	            
	            prev = i;
	            
	        }
	    }
	    
	    return ans;
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends