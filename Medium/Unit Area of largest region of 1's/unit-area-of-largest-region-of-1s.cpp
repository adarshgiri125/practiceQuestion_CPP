//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        queue<pair<int,int> > q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                    int count = 1;
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                       
                        q.pop();
                        
                        for(int i = -1; i<=1; i++){
                            for(int j = -1; j<=1; j++){
                                int nrow = r + i;
                                int ncol = c + j;
                                
                                if(nrow < n && nrow >=0 && ncol < m && ncol >=0 && !vis[nrow][ncol] && grid[nrow][ncol] == 1 ){
                                    count++;
                                    vis[nrow][ncol] = 1;
                                    
                                     q.push({nrow,ncol});
                                     
                                }
                            }
                        }
                        
                        
                        
                    }
                    
                    ans = max(ans,count);
                    
                    
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends