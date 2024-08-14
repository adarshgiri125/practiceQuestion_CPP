//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        string req="";
        string diff ="";
        int n= str1.length();
        int m = str2.length();
        int size =0;
        int maxi =0;
        if(n<m){
            size =n;
            req=str1;
            diff = str2;
            
        }
        else{
            size=m;
            req=str2;
            diff =str1;
        }
        int i=0;
        int j=1;
        while(j<size+1){
            string ans = req.substr(i,j);
            size_t found = diff.find(ans);
            if (found != string::npos){
                int count=ans.size();
                maxi = max(maxi,count);
                j++;
            }
            else{
                i++;
                j=1;
            }
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends