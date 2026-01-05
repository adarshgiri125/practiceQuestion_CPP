class Solution {
  public:
  
    class DisjointSet{
        vector<int> rank,size,parent;
        public :
        DisjointSet(int n){
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);
            parent.resize(n + 1, 0);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
            }
        }
        
        
        int findUP(int node){
            if(node == parent[node]){
                return node;
            }
            else return parent[node] = findUP(parent[node]);
        }
        
        void unionByRank(int u,int v){
            int up_u = findUP(u);
            int up_v = findUP(v);
            
            if(rank[up_u] > rank[up_v]){
                parent[up_v] = up_u;
            }
            else if(rank[up_v] > rank[up_u]){
                parent[up_u] = up_v;
            }
            else{
                parent[up_u] = up_v;
                rank[up_v]++;
            }
        }
    };
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int n = edges.size();
        
        for(int i = 0; i<n; i++){
            reverse(edges[i].begin(), edges[i].end());
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int sum = 0;
        for(int i = 0; i<n; i++){
            int u = edges[i][1];
            int v = edges[i][2];
            int w = edges[i][0];
            
            if(ds.findUP(u) != ds.findUP(v)){
                sum += w;
                ds.unionByRank(u,v);
            }
        }
        return sum;
        
    }
};