//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void mark_conn(vector<vector<int> > &vis, vector<vector<char> > &grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[i][j] = 1;
        
        for(int u = -1; u<= 1; u++){
            for(int v = -1; v<= 1; v++){
                int new_row = i + u;
                int new_col = j + v;
                
                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == '1' && vis[new_row][new_col] == 0){
                    mark_conn(vis,grid,new_row, new_col);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int> > vis(n,vector<int> (m,0));
        int ans = 0;
       for(int i = 0; i<n; i++){
           for(int j = 0; j<m; j++){
               if((vis[i][j] == 0) && (grid[i][j] == '1')){
        
                   ans++;
                   mark_conn(vis,grid,i,j);
               }
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends