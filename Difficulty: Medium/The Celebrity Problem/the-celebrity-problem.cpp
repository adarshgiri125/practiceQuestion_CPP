//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int> > adj(n);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                 int val = mat[i][j];
                 if(val == 1) adj[i].push_back(j);
            }
        }
        
        for(int i = 0; i<n; i++){
            bool check = false;
            if(adj[i].size() == 0){
                int cnt = 0;
                for(int j = 0; j<n; j++){
                    if(j != i){
                        for(auto k : adj[j]){
                            if(k == i){
                                cnt++;
                                break;
                            }
                        }
                    }
                }
                if(cnt == n-1) return i;
            }
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends