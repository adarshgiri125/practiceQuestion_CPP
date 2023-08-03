//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int > > adj[n+1];
        
        for(int i = 0; i< m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        set<pair<int,int> >st;
        vector<int> distance(n+1, INT_MAX); 
        vector<int> position(n+1);
        for(int i = 1; i<=n; i++) position[i] = i;
        distance[1] = 0; 
        st.insert({0,1});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int dist = it.first;
            int node = it.second;
            
            st.erase(it);
            
            for(auto i : adj[node]){
                if(i.second + dist < distance[i.first]){
                    distance[i.first] = i.second + dist;
                    position[i.first] = node;
                    
                    st.insert({distance[i.first],i.first});
                }
                
            }
        }
        if(distance[n] == INT_MAX){
            return {-1};
        }
        
        vector<int> ans;
        int node = n;
        while(position[node] != node){
            ans.push_back(node);
            node = position[node];
            
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
    }
      
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends