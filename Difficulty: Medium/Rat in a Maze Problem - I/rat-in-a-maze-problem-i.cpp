//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int r[4] = {-1,0,1,0};
    int c[4] = {0,1,0,-1};
    char dir[4] = {'U','R','D','L'};
    vector<string> ans;
    void solve(vector<vector<int>> &mat,int row, int col, vector<vector<int> > 
    vis, string &temp){
        
       
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
         if(row == n-1 && col == m - 1){
             ans.push_back(temp);
             return;
         }
        for(int i = 0; i<4; i++){
            int new_r = r[i] + row;
            int new_c = c[i] + col;
         
            
            if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && mat[new_r][new_c] == 1 && vis[new_r][new_c] != 1 ){
               temp += dir[i];
               solve(mat,new_r,new_c, vis, temp);
               temp.pop_back();
            }
        }
        vis[row][col] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        string temp;
        if(mat[0][0] == 0) return ans;
        solve(mat,0,0,vis, temp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends