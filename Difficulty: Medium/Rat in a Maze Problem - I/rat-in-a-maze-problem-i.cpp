//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int r[4] = {-1, 0, +1, 0};
    int c[4] = { 0, +1, 0, -1};
    char dir[4] = {'U', 'R', 'D', 'L'};
    void solve(vector<vector<int>> &mat, int i, int j, vector<vector<int> > &vis, vector<string> &ans, string &temp){
        int n = mat.size();
     
        if(i < 0 || j > n-1 || i > n - 1 || j < 0 || vis[i][j] == 1 || mat[i][j] == 0)return;
        if(i == n - 1 && j == n - 1){
            ans.push_back(temp);
            return;
        } 
        vis[i][j] = 1; 
        
        for(int d = 0; d<4; d++){
            int row = i + r[d];
            int col = j + c[d];
            
            temp += dir[d];
            
            solve(mat,row,col,vis,ans,temp);
            
            temp.pop_back();
        }
        
        vis[i][j] = 0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<string> ans;
        vector<vector<int> > vis(n,vector<int> (m, 0));
        string temp = "";
        solve(mat,0,0,vis,ans,temp);
        sort(ans.begin(),ans.end());
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