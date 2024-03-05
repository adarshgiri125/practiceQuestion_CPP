//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
   vector<int>primes; 

    void precompute(){

    long long int n=1e7+1; 

    bool*prime=new bool[n]; // n is large hence used heap (dynamic allocation) 

    for(long long int i=0;i<n;++i){

        prime[i]=true; 

    }

    for (long long int p = 2; p * p <= n; p++) {       

         if(prime[p] ==false)

            continue;                  

        for(long long int i = p * p; i <= n; i += p){

          prime[i] = false;

        } 

       

    }

    for (long long int p = 2; p <= n; p++){

        if(prime[p]){

            primes.push_back(p); 

        } 

    }    

    }

    void dfs(int u,bool visited[],vector<int>adj[],int&group_size){

        visited[u]=true;

        group_size++; 

        for(auto&child:adj[u]){

            if(!visited[child]){

                dfs(child,visited,adj,group_size); 

            }

        }

    }

    int helpSanta(int n, int m, vector<vector<int>> &g){

        // Code here

        if(m==0) return -1; 

        vector<int> adj[n+1]; 

        for(auto&val:g){

            int u=val[0];

            int v=val[1];

            adj[u].push_back(v);

            adj[v].push_back(u);

        }

        bool visited[n+1]={false};

        int k=1; 

        for(int i=1;i<=n;++i){ 

            if(!visited[i]){

                int group_size=0; 

                dfs(i,visited,adj,group_size);

                k=max(k,group_size); 

            }

        }

        if(k==1) return -1;      

        return primes[k-1]; 

    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g;
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g.push_back({u, v});
// 			g[u].push_back(v);
// 			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends