//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string solve(string S, int s, int e){
        int n = S.size();
        while(s>=0 && e < n){
            if(S[s] == S[e]){
                s--;
                e++;
            }
            else{
                break;
            }
            
        }
        return S.substr(s+1,e - s - 1);
    }
    string longestPalin (string S) {
        
        int n = S.size();
        int length = 0;
        string ans = "";
        for(int i = 0; i<n; i++){
            string curr = solve(S,i,i);
            if(curr.size() > length){
               
                ans = curr;
                length = curr.size();
                
            }
            
            curr = solve(S,i,i+1);
            if(curr.size() > length){
                
                ans = curr;
                length = curr.size();
            }
            
            
        }
        return ans;
    }
    
  
    //this is brute force with time complexity of O(n3);;
    // bool isPalind(string curr){
    //     int s = 0;
    //     int e = curr.size()-1;
        
    //     while(s<e){
    //         if(curr[s] != curr[e]){
    //             return false;
    //         }
    //         s++;
    //         e--;
    //     }
    //     return true;
        
    // }
    // string longestPalin (string S) {
    //     string ans = "";
    //     int length = 0;
    //     for(int i = 0; i<S.size(); i++){
            
    //         string curr = "";
    //         for(int j = i; j<S.size(); j++){
    //             curr += S[j];
    //             if(isPalind(curr)){
    //                 if(curr.size() > length){
    //                     ans = curr;
    //                     length = curr.size();
    //                 }
                    
    //             }
    //         }
    //     }
    //     return ans;
    // }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends