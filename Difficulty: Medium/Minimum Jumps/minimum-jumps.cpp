//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(int i, vector<int> &a, vector<int> &dp){
        if(i==a.size()-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int res = INT_MAX;
        for(int j = i+1 ; j<=min(i+a[i], int(a.size()-1));j++){
            int c = fun(j, a, dp);
            
            if(c!=INT_MAX)
                res = min(res,1+c);
        }
        
        return dp[i] = res;
    }
  
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n+1, -1);
        
        int ans = fun(0, arr, dp);
        return ans==INT_MAX?-1:ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends