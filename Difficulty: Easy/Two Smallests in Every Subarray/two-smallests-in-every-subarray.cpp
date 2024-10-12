//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        if(n == 1) return -1;
        int ans = 0;
        for(int i = 0; i<n - 1; i++){
            int sum = arr[i] + arr[i + 1];
            ans = max(sum, ans);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends