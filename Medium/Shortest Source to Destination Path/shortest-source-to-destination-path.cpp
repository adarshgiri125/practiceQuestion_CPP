//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    // int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        
    //     int ans = 0;
    //     vector<pair<int,int> > adj;
    //     vector<vector<int> > vis(N,vector<int> (M,0));
    //     queue<pair<pair<int,int>,int > >q;
    //     q.push({{0,0},0});
    //     vis[0][0] = 1;
        
    //     int output = 0;
    //     int drow[] = {-1, 0, +1, 0};
    //     int dcol[] = {0,+1,0,-1};
    //     while(!q.empty()){
    //         int row = q.front().first.first;
    //         int col = q.front().first.second;
    //         int ds = q.front().second;
    //           ans = max(ds,ans); 
    //           q.pop();
            
    //         for(int i = 0; i<4; i++){
    //             int nrow = row + drow[i];
    //             int ncol = col + dcol[i];
                
    //             if(nrow == X && ncol == Y){
    //               output = min(ds, ans);
                    
    //             }
    //             if(nrow < N && nrow>=0 && ncol >=0 && ncol< M && vis[nrow][ncol] != 1 && A[nrow][ncol] == 1){
    //                 q.push({{nrow,ncol},ds+1});
    //                 vis[nrow][ncol] = 1;
    //             }
                
    //         }
            
    //     }
        
    //     return output;
        
        
        
    // }
    
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    int ans = 0;
    vector<pair<int,int>> adj;
    vector<vector<int>> vis(N, vector<int>(M, 0));
    queue<pair<pair<int,int>, int>> q;
    q.push({{0, 0}, 0});
    vis[0][0] = 1;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int ds = q.front().second;
        ans = max(ds, ans);
        q.pop();

        if (row == X && col == Y) {
            return ds; 
        }

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && vis[nrow][ncol] != 1 && A[nrow][ncol] == 1) {
                q.push({{nrow, ncol}, ds + 1});
                vis[nrow][ncol] = 1;
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