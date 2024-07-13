//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    using T = pair<int, int>;
    vector<vector<pair<int, int>>> adj(n + 1);

    // Create the adjacency list
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<T, vector<T>, greater<T>> pq;
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1, -1);
    
    // Starting from node 1
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (const auto& next : adj[node]) {
            int nextNode = next.first;
            int edgeWeight = next.second;
            if (dist[nextNode] > weight + edgeWeight) {
                dist[nextNode] = weight + edgeWeight;
                pq.push({dist[nextNode], nextNode});
                parent[nextNode] = node;
            }
        }
    }

    // If there's no path to node n
    if (dist[n] == 1e9) {
        return {-1};
    }

    // Reconstruct the path from 1 to n
    vector<int> path;
    for (int at = n; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    // Result should be the weight followed by the path
    path.insert(path.begin(), dist[n]);

    return path;
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
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends