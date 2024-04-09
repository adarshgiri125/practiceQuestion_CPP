//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

private:
    int solve(vector<vector<int>> &grid,int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1) return ((grid[i][j]>=0 ? 1:((abs(grid[i][j])+1))));
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=min(solve(grid,i+1,j,n,m,dp),solve(grid,i,j+1,n,m,dp));
        return dp[i][j]=max(ans-grid[i][j],1);
    }
	public:
	int minPoints( int M, int N,vector<vector<int>> &grid) 
	{ 
	    vector<vector<int>> dp(M+1,vector<int>(N+1,-1));
	    return solve(grid,0,0,M,N,dp);
	} 
// 	int ans = INT_MIN;

// 	void solve(int m, int n, vector<vector<int>> &points,int i, int j,int cost){
// 	    if(i < 0 || j < 0 || i>= m || j >= n){
// 	        return;
// 	    }
	  
// 	    if(i == n - 1 && j == m-1){
	         
// 	       if(points[i][j] < 0){
//              cost += points[i][j]; 
//           }
// 	       ans = max(ans,cost);
// 	       return;
// 	    }
//         if(points[i][j] < 0){
//             cost += points[i][j]; 
//         }
	   
// 	    solve(m,n,points,i+1,j,cost);
// 	    solve(m,n,points,i,j+1,cost);
// 	    if(points[i][j] < 0){
//             cost -= points[i][j]; 
//         }
	
// 	}
// 	int minPoints(int m, int n, vector<vector<int>> points) 
// 	{ 
// 	    int cost = 0;
// 	    solve(m,n,points,0,0,cost);
// 	    return 1 + abs(ans);
	    
// 	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends