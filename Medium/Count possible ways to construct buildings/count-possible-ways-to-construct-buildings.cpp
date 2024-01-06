//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    long long  x = 0 , y = 1;
	  int mod = 1e9+7;
	  
	  for(int i = 1 ; i<=N+1;i++){
	      swap(x,y);
	      y = (y + x)%mod;
	  }
	  return (y*y)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends