//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int r[4] = {-1,0,1,0};
    int c[4] = {0,1,0,-1};
    int ans = INT_MAX;
    void solve(int row, int col,vector<vector<int>> &a, int x, int y
    , vector<vector<int>> &vis, int temp){
        int n = a.size();
        int m = a[0].size();
        if(row == x && col == y){
            ans = min(ans,temp);
            return;
        }
        vis[row][col] = 1;
        temp += 1;
        
        for(int i = 0; i<4; i++){
            int nr = r[i] + row;
            int nc = c[i] + col;
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m
            && vis[nr][nc] != 1 && a[nr][nc] == 1){
              
                
                solve(nr,nc,a,x,y,vis,temp);
                
                
            }
        }
        temp -= 1;
        vis[row][col] = 0;
    }
    int shortestDistance(int n, int m, 
    vector<vector<int>> a, int x, int y) {
        // code here
        int temp = 0;
        vector<vector<int> > vis(n, vector<int> (m,0));
        // solve(0,0,A,x,y,vis,temp);
        // return ans;
        if(a[0][0] == 0) return -1;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push(make_tuple(0,0,0));
        vis[0][0] = 1;
        
        while(!pq.empty()){
            int val = std::get<0>(pq.top());
            int row = std::get<1>(pq.top());
            int col = std::get<2>(pq.top());
            
            pq.pop();

            
            if(row == x && col == y && a[row][col] == 1) return val;
            for(int i = 0; i<4; i++){
                int nr = r[i] + row;
                int nc = c[i] + col;
                
                
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m
                && vis[nr][nc] != 1 && a[nr][nc] == 1){
                    vis[nr][nc] = 1;
                   pq.push(make_tuple(val + 1, nr, nc));
                    
                }
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends