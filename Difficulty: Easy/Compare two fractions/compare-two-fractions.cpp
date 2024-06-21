//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   string compareFrac(string s) {
    const size_t p{ s.find( ',' )};
    string s1{ s.substr( 0, p )}, s2{ s.substr( p + 2 )};
    int l{ stoi( s1 ) * stoi( s2.substr( s2.find( '/' ) + 1 ))};
    int r{ stoi( s2 ) * stoi( s1.substr( s1.find( '/' ) + 1 ))};
    if(l==r) return "equal";
    else if(l>r) return s1;
    return s2;
        
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends