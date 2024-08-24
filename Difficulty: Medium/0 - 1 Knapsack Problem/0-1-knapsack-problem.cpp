//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, vector<int>& wt, vector<int>& val, int ind){
        if(ind >= wt.size() ) return 0;
        if(W == 0) return 0;
        int sum = 0;
        int sum2= 0;
        if(W >= wt[ind]){
            sum = val[ind] + solve(W - wt[ind], wt, val, ind+1);
        }
        sum2 = solve(W,wt,val,ind + 1);
        
        return max(sum , sum2);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        return solve(W, wt, val, 0);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends