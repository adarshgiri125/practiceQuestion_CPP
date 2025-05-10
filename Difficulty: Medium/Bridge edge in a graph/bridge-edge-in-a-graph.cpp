//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void f(int node, vector<int>adj[], vector<int>&vis) {
        
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            vis[front] = 1;
            
            for(auto it:adj[front]){
                 if(vis[it]== 0){
                     q.push(it);
                 }
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<int>adj[V];
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int counter = 0;
        vector<int>vis(V, 0);
        
        for(int i = 0;i<V;i++) {
            if(vis[i] == 0){
                counter++;
                f(i ,adj, vis);
            }
        }
        vector<int>adj2[V];
        
        for(auto store : edges) {
            int u = store[0];
            int v = store[1];
            if((u == c and v == d) or (u == d and v == c)){
                continue;
            }
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int counter2 = 0;
        vector<int>vis2(V, 0);
        for(int i= 0 ;i<V;i++) {
            if(vis2[i]==0){
                counter2 ++;
                f(i, adj2, vis2);
            }
        }
        return counter2 > counter;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends