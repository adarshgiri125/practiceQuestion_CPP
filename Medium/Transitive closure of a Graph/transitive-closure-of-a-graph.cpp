//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void dfs(int node,vector<int> &visited,vector<int> adj[])
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            dfs(it,visited,adj);
        }
    }

    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<int> adj[N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i!=j and graph[i][j])
                adj[i].push_back(j);
            }
        }
        for(int i=0;i<N;i++)
        {
            vector<int> visited(N,0);
            dfs(i,visited,adj);
            for(int j=0;j<N;j++)
            if(visited[j])
            graph[i][j]=1;
        }
        return graph;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends