//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int>> >, greater<pair<int,pair<int,int>> > > pq;
        vector<vector<int> >distance(n,vector<int> (m,INT_MAX));
        
        pq.push({0,{source.first,source.second}});
        distance[source.first][source.second] = 0;
        
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dist = pq.top().first;
            
            pq.pop();
            
            for(int i = 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow < n && nrow >= 0 && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                    if(dist + 1 < distance[nrow][ncol]){
                        distance[nrow][ncol] = dist + 1;
                        pq.push({dist + 1,{nrow,ncol}});
                    }
                    
                }
            }
            
            
        }
        if(distance[destination.first][destination.second] == INT_MAX){
            return -1;
        }
        return distance[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends