//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
   
    void matchPairs(int n, char nuts[], char bolts[]) {
    vector<char> v(nuts, nuts + n);
    vector<char> v1(bolts, bolts + n);
    unordered_map<char, int> mp;

    mp['!'] = 1;
    mp['#'] = 2;
    mp['$'] = 3;
    mp['%'] = 4;
    mp['&'] = 5;
    mp['*'] = 6;
    mp['?'] = 7;
    mp['@'] = 8;
    mp['^'] = 9;

    sort(v.begin(), v.end(), [&mp](char a, char b) {
        return mp[a] < mp[b];
    });

    sort(v1.begin(), v1.end(), [&mp](char a, char b) {
        return mp[a] < mp[b];
    });

 
    for (int i = 0; i < n; i++) {
        nuts[i] = v[i];
        bolts[i] = v1[i];
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
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends