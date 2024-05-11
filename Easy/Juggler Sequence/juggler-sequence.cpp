//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        long long value = n;
        vector<long long> ans;
        while(value > 1){
            ans.push_back(value);
            if(value % 2 == 0){
                value = pow(value,0.5);
            }
            else{
                value = pow(value,1.5);
            }
        }
        if(value == 1)
          ans.push_back(1);
          
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends