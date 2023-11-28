//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        vector<vector<int>> v(V);  // Initialize v with V empty vectors
    
        for (int i = 0; i < V; i++) {
            for (int u : adj[i]) {
                v[u].push_back(i);  // Push i as a dependency of node u
            }
        }
    
        int ans = 0;
        for (auto i : v) {
            int val = i.size();
            ans += val;
        }
        return ans;
   } 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}
// } Driver Code Ends