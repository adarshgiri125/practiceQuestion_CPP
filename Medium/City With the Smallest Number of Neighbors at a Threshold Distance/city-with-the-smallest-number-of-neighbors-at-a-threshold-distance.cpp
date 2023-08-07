//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
         
         vector<vector<int> > mat(n,vector<int> (n,1e9));
         
         for(int i = 0; i<m; i++){
             int u = edges[i][0];
             int v = edges[i][1];
             int w = edges[i][2];
             
             
               mat[u][v] = w;
               mat[v][u] = w;  
             
             
         }
         for(int i = 0; i<m; i++){
             mat[i][i] = 0;
         }
         
         
         
         
         for(int k = 0; k<n; k++){
             for(int i = 0; i<n; i++){
                 for(int j = 0; j<n; j++){
                     if(mat[i][k] == 1e9 || mat[k][j] == 1e9) continue;
                     mat[i][j] = min(mat[i][j] , mat[i][k] + mat[k][j]);
                 }
             }
         }
         
         int count = n;
         int city = -1;
         
         for(int i = 0; i<n; i++){
             int c = 0;
             for(int j = 0; j<n; j++){
                 if(mat[i][j] <= distanceThreshold){
                     c++;  
                 }
             }
             if(c <= count){
                count = min(count,c);
                city = i;
             }
             
             
         }
         
         return city;
                     
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends