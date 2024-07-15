//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   string smallestNumber(int s, int d) {
    // If the sum of digits s is greater than the maximum possible sum with d digits
    if (s > 9 * d) {
        return "-1";
    }
    // If s is 0, we can only form a valid number if d is 1
    if (s == 0) {
        return (d == 1) ? "0" : "-1";
    }

    // Initialize the result with '0's
    string res(d, '0');
    
    // Start filling the number from the most significant digit
    for (int i = d - 1; i >= 0; i--) {
        if (s > 9) {
            res[i] = '9';
            s -= 9;
        } else {
            res[i] = '0' + s;
            s = 0;
        }
    }

    // Ensure the number is the smallest by fixing leading zeros
    if (res[0] == '0') {
        for (int i = 1; i < d; i++) {
            if (res[i] != '0') {
                res[i] -= 1;
                res[0] = '1';
                break;
            }
        }
    }

    return res;
}

};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends