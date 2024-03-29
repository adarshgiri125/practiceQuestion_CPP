//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool check(int parent, queue<int>& q, int color[], vector<int> adj[], int V) {
    q.push(parent);
    color[parent] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

            for (auto i : adj[node]) {
                if (color[i] == -1) {
                    color[i] = !color[node];
                    q.push(i);
                } else if (color[i] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[]) {
        queue<int> q;
        int color[V];
        memset(color, -1, sizeof(color));
    
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (check(i, q, color, adj, V) == false) {
                    return false;
                }
            }
        }
        return true;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends