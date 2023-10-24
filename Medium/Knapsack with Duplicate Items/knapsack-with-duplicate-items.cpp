//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve( int w, int v[], int Wt[],int ind,vector<vector<int>> &dp){
    
        if(ind == 0){
            int r =  w / Wt[ind];
            return r * v[ind];
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int notake = 0 + solve(w,v,Wt,ind-1,dp);
        int take = INT_MIN;
        if(w - Wt[ind] >= 0) take = v[ind] + solve(w - Wt[ind],v,Wt,ind,dp);
        
        return dp[ind][w] = max(notake,take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
    
        // vector<vector<int>> dp(N, vector<int> (W+1,0));
        vector<int> prev(W+1, 0);
        // return solve(W,val,wt,N-1,dp);
        for(int w = 0; w<=W; w++) prev[w] = ((int) (w/wt[0])) * val[0];
        
        for(int ind = 1; ind<N; ind++){
            for(int w = 0; w <= W; w++){
                int notake = 0 + prev[w];
                int take = 0;
                if(w - wt[ind] >= 0) take = val[ind] +prev[w - wt[ind]];
                
                prev[w] = max(notake,take);
            }
          
        }
        
        return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends