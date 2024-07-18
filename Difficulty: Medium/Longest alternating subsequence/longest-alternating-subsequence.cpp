//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int rec(int idx, vector<int>& arr, int n, vector<vector<int>>& dp, bool dir) {
        if (idx >= n) {
            return 0;
        }

        if (dp[idx][dir] != -1) {
            return dp[idx][dir];
        }

        // take
        int take = 0;
        if (dir) { 
            if (idx == 0 || arr[idx] > arr[idx - 1]) {
                take = 1 + rec(idx + 1, arr, n, dp, false);
            }
        } else { 
            if (idx == 0 || arr[idx] < arr[idx - 1]) {
                take = 1 + rec(idx + 1, arr, n, dp, true);
            }
        }

        // not take
        int notTake = rec(idx + 1, arr, n, dp, dir);

        return dp[idx][dir] = max(take, notTake);
    }

    int alternatingMaxLength(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        return max(rec(0, arr, n, dp, true), rec(0, arr, n, dp, false));
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends