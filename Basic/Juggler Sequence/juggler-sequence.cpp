//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> ans;
    
    vector<int> jugglerSequence(int N){
        ans.push_back(N);
        if(N == 1) return ans;
        if(N % 2 == 0){
            int value = pow(N,0.5);
            return jugglerSequence(value);
         }
         else{
            int value = pow(N,1.5);
            return jugglerSequence(value);
         }
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
        vector<int> ans = ob.jugglerSequence(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends