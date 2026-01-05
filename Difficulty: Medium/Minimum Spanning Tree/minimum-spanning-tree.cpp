class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int> > > adj(V);
        
        for(auto node : edges){
            int u = node[0];
            int v = node[1];
            int w = node[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        // code here
        priority_queue<pair<int,int> , vector<pair<int,int> >, greater<> > pq;
        
        vector<int> vis(V,0);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto [value, node] = pq.top();
            pq.pop();
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += value;
            
            for(auto edge : adj[node]){
                int node = edge.first;
                int w = edge.second;
                if(vis[node] != 1){
                    pq.push({w,node});
                }
                
            }
            
            
        }
        return sum;
        
    }
};