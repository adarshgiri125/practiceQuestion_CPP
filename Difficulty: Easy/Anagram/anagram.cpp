//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        int n = s1.length();
        if(n != s2.length())
        {
            return false;
        }
        int chars[26] = {0};
        
        for(int i = 0; i<n ; i++)
        {
            chars[s1[i] - 'a']++;
        }
        for(int i = 0; i<n; i++)
        {
            int idx = s2[i] - 'a';
            if(chars[idx] == 0)
                return false;
            chars[idx]--;    
        }
        
        return true;
    }


};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends