//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int v, vector<int> &visited, vector<vector<int>> &adj) {
    visited[v] = 1;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, visited, adj);
        }
    }
}

bool isEulerianCircuit(vector<string> &arr) {
    vector<vector<int>> adj(26); // Adjacency list for graph
    vector<int> inDegree(26, 0), outDegree(26, 0);
    
    // Build graph
    for (string &s : arr) {
        int start = s[0] - 'a'; // First character
        int end = s.back() - 'a'; // Last character
        adj[start].push_back(end);
        outDegree[start]++;
        inDegree[end]++;
    }
    
    // Check if in-degree and out-degree of all characters are equal
    for (int i = 0; i < 26; i++) {
        if (inDegree[i] != outDegree[i]) {
            return false; // Not an Eulerian circuit
        }
    }
    
    // Check if all vertices with edges are in the same connected component
    vector<int> visited(26, 0);
    int startVertex = -1;
    for (int i = 0; i < 26; i++) {
        if (outDegree[i] > 0) {
            startVertex = i; // Start DFS from any vertex with an edge
            break;
        }
    }

    if (startVertex == -1) return true; // No edges at all

    dfs(startVertex, visited, adj);

    // Ensure all vertices with an edge are visited
    for (int i = 0; i < 26; i++) {
        if ((inDegree[i] > 0 || outDegree[i] > 0) && !visited[i]) {
            return false; // Not strongly connected
        }
    }
    
    return true;
}

int isCircle(vector<string> &arr) {
    return isEulerianCircuit(arr) ? 1 : 0;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends