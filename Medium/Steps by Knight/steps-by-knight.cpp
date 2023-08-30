//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int srow = KnightPos[1];
	    int scol = KnightPos[0];
	    
	    int erow = TargetPos[1];
	    int ecol = TargetPos[0];
	    
	    vector<vector<int> > vis(n+1,vector<int> (n+1,0));
	    queue<pair<int,pair<int,int> > > q;
	    q.push({0,{srow,scol}});
	    vis[srow][scol] = 1;
	    
	    int row[] = {1,-1,1,-1,2,2,-2,-2};
	    int col[] = {2,2,-2,-2,1,-1,1,-1};
	    while(!q.empty()){
	        int nrow = q.front().second.first;
	        int ncol = q.front().second.second;
	        int steps =  q.front().first;
	        q.pop();
	        
	        if(nrow == erow && ncol == ecol){
	            return steps;
	        }
	        
	        for(int i= 0; i<8; i++){
	            int frow = nrow + row[i];
	            int fcol = ncol + col[i];
	            
	            if(frow >= 1 && frow <=n && fcol >=1 && fcol <=n && !vis[frow][fcol]){
	                vis[frow][fcol] = 1;
	                q.push({steps+1,{frow,fcol}});
	            }
	        }
	      
	        
	    }
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends