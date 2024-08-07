//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        int i = 0;
        int n = str.size();
        int count = 0;
        int dot = 0;
        while(i < n){
            string a = "";
            while(i < n && str[i] != '.'){
                a.push_back(str[i]);
                i++;
            }
            dot++;
            if(a.size() > 1 && a[0] == '0') return 0;
            if(a.size() > 1){
                int v = stoi(a);
                // cout << v << " ";
                if(v > 255 || v < 0) return 0;  
            }
            
            if( i < n && str[i + 1] == '.') return 0;
            i++;
            
        }
        if(dot > 4 || dot < 4) return 0;
        
        return 1;
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends