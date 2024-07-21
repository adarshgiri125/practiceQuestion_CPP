//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int neg = 0;
        int mini = INT_MIN;
        int mod = 1e9 + 7;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] < 0){
                neg++;
                if(arr[i] > mini){
                    mini = arr[i];
                }
            }
        }
        
        long long int ans = 1;
        
        bool one = false;
        bool mone = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == 1) one = true;
            if(arr[i] == -1) mone++;
            if(arr[i] != 0 ) ans = (ans * arr[i]) % mod;
        }
       
        
        if(ans == 1 && one || ans == 1 && mone >= 2) return ans;
        else if(ans == 1) return 0;
        
        if(neg % 2 == 0){
            return (ans) % mod;
        }
        else{
            return ((ans / mini)) % mod; 
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends