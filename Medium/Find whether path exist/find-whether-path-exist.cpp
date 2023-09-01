//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        queue<pair<int,int> > q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > vis(n+1,vector<int> (m+1,0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        int row[] = {0,-1,0,1};
        int col[] = {-1,0,1,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow = r + row[i];
                int ncol = c + col[i];
                
                if(nrow < n && nrow >= 0 && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] != 0){
                    if(grid[nrow][ncol] == 2){
                        return true;
                    }
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends