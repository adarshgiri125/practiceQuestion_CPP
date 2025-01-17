//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size(), prod = 1, zero = 0;
        for(int& val : arr) {
            if(val!=0)  prod *= val;
            else zero++;
        }
        vector<int> ans(n, 0);
        if(zero>1)  return ans;
        
        for(int i=0; i<n; i++)  ans[i] = (zero ? arr[i]==0 ? prod : 0 : prod/(arr[i]==0 ? 1 : arr[i]));
        return ans;
    }


};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends