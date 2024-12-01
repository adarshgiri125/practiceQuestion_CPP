//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        const int CHAR=256;
       int res=INT_MAX;
        int count[CHAR];
        fill(count,count+CHAR,-1);
        for(int i=0; i<s.length(); i++){
            if(count[s[i]]==-1){
                count[s[i]]=i;
            }
            else{
                count[s[i]]=-2;
            }
        }
        for(int i=0; i<CHAR; i++){
            if(count[i]>=0){
                res=min(res,count[i]);
            }
        }
        
        if(res != INT_MAX){
        return s[res];
        }
        else{
            return '$';
        }
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends