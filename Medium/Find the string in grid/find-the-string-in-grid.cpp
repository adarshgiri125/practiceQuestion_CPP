//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   bool solve(int i,int j,int addx,int addy,int k,string &word,vector<vector<char>>&grid,int n,int m,vector<vector<int>>&ans)
    {   if(k==word.size())return true;
        if(i<0||i>=n||j<0||j>=m||grid[i][j]!=word[k])return false;
        return solve(i+addx,j+addy,addx,addy,k+1,word,grid,n,m,ans);
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>>ans;
	    int n=grid.size();
	    int m=grid[0].size();
	    int  x[]={-1,0,1,0,-1,1,1,-1};
	    int  y[]={0,1,0,-1,1,1,-1,-1,};
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(word[0]==grid[i][j]){
	               for(int k=0;k<8;k++){
	                   if(solve(i+x[k],j+y[k],x[k],y[k],1,word,grid,n,m,ans)){
	                       ans.push_back({i,j});
	                       break;
	                   }
	               }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends