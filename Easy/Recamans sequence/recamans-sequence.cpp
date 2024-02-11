//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     vector<int> recamanSequence(int n){
        // code here
        vector<int> ans ;
        unordered_set<int> st;
        for(int i = 0;i<n;i++){
            if(i==0) {
                ans.push_back(i);
                st.insert(i);
            }else{
                  int check = ans[i-1]-i;
                  if(check>0 && st.insert(check).second) ans.push_back(check);
                  else {
                      check = ans[i-1]+i;
                      ans.push_back(check);
                      st.insert(check);
                  }
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
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends