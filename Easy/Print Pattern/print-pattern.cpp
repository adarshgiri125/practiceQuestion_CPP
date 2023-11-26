//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve2(int last,int n, vector<int> &ans){
        if(last >= n){
            ans.push_back(last);
            return; 
        }
        ans.push_back(last);
        solve2(last + 5, n, ans);
    }
    void solve(int n, vector<int> &ans,int &last){
        if(n <= 0){
            last = n;
            return;
        }
        
        ans.push_back(n);
        solve(n - 5,ans,last);
        
    }
    
    vector<int> pattern(int N){
        vector<int> ans;
        int last;
        solve(N,ans,last);
        solve2(last, N,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends