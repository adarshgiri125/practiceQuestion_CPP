//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int> > adj(N);
        
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<pair<int,int> > q;
        
        q.push({src,0});
        vector<int> dis(N,-1);
        dis[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            
            for(auto edge : adj[node]){
                int nod = edge;
                if(dis[nod] == -1 || dis[nod]  > d + 1){
                    dis[nod] = d + 1;
                    q.push({nod,d + 1});
                }
            }
        }
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends