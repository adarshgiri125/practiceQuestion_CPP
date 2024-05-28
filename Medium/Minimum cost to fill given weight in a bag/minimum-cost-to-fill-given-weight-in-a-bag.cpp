//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
     int minimumCost(int n, int w, vector<int> &cost) {
        // vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        vector<int>prev(w+1,0),curr(w+1,0);
        for(int i=1;i<=w;i++){
            prev[i]=i*cost[0];
            curr[i]=prev[i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=w;j++){
                int pick=1e9;
                if(j>=(i+1)){
                    pick=curr[j-i-1]+cost[i];
                }
                int notpick=prev[j];
                curr[j]=min(pick,notpick);
            }
            prev=curr;
        }
        return prev[w];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends