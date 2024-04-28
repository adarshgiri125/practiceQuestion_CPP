//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        int left = 0;
        int right = 0;
        int ans = 0;
        
        for(int i = 0; i<S.size(); i++){
            if(S[i] == '(') left++;
            else right++;
            
            if(left == right){
                ans = max(ans,2 * left);
            }
            else if(right > left){
                left = 0;
                right = 0;
            }
        }
        
        left = 0;
        right = 0;
        
        for(int i = S.size() - 1; i >= 0; i--){
            if(S[i] == '(') left++;
            else right++;
            
            if(left == right){
                ans = max(ans,2 * left);
            }
            else if(left > right){
                left = 0;
                right = 0;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends