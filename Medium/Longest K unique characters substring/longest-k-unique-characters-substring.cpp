//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:


int longestKSubstr(string S, int k) {
    int ans = -1; 
    unordered_map<char, int> mp; 
    int left = 0; 
    int uniqueCount = 0; 

    for (int right = 0; right < S.size(); right++) {
      
        mp[S[right]]++;
        if (mp[S[right]] == 1) {
            uniqueCount++;
        }

       
        while (uniqueCount > k) {
            mp[S[left]]--;
            if (mp[S[left]] == 0) {
                uniqueCount--;
            }
            left++;
        }

        if (uniqueCount == k) {
            ans = max(ans, right - left + 1);
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends