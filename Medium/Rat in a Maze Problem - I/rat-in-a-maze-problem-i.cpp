//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int newx, int newy,vector<vector<int>> &m,int n,vector<vector<bool> > &vis ){
        if( (newx >=0 && newx < n) && (newy >=0 && newy < n)   && vis[newx][newy] != 1 && m[newx][newy] == 1){
            return true;
        }
        else
        return false;
    }
    
    
    void solve(int x, int y,  vector<string> &ans,vector<vector<bool> > &vis, vector<vector<int>> &m, int n,string path ){
        
        if(x == n -1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        //Movement D L R U
        
        if(isSafe(x + 1, y, m, n,vis)){
            vis[x][y] = 1;
           solve(x+1, y, ans,vis,m,n, path + 'D');
           vis[x][y] = 0;
        }
        
        if(isSafe(x , y - 1, m, n,vis)){
            vis[x][y] = 1;
           solve(x, y - 1, ans,vis,m,n, path + 'L');
           vis[x][y] = 0;
        }
        
        if(isSafe(x , y + 1, m, n,vis)){
            vis[x][y] = 1;
           solve(x, y + 1, ans,vis,m,n, path + 'R');
           vis[x][y] = 0;
        }
        
        if(isSafe(x - 1, y, m, n,vis)){
            vis[x][y] = 1;
           solve(x-1, y, ans,vis,m,n, path + 'U');
           vis[x][y] = 0;
        }
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool> > vis (n, vector<bool> (n,0));
        string path = "";
        if (m[0][0] == 0){
            return ans;
        }
        
        solve(0,0,ans,vis,m,n,path);
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends