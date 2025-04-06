//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n , m ;
    void dfs(int i , int j , vector<vector<char>>& grid ,vector<vector<int>>& visited){
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 1 || grid[i][j] == 'W'){
            return ;
        }
        
            visited[i][j]  = 1; //  down
            
            dfs(i+1,j,grid,visited); // Donw
            dfs(i-1,j,grid,visited); // UP
            dfs(i,j+1,grid,visited); // Right
            dfs(i,j-1,grid,visited); // Left
            dfs(i-1,j+1,grid,visited); // Dia TOP right
            dfs(i-1,j-1,grid,visited); // Dia TOp left
            dfs(i+1,j-1,grid,visited); // Dia bottom left
            dfs(i+1,j+1,grid,visited); // Dia bottom right

    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
          int ans = 0;
          n = grid.size();
          m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                 if(grid[i][j] == 'L' && visited[i][j] != 1){
                     dfs(i,j,grid,visited);
                     ans++;
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
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends