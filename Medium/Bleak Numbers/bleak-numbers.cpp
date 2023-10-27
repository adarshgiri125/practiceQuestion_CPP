//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    if(n<=100){
	        for(int i=1;i<=100;i++){
	            int x=__builtin_popcount(i);
	            if(x+i==n) return 0;
	        }
	        return 1;
	    }
	    
	    for(int i=32;i>=1;i--){
	        int x=__builtin_popcount(n-i);
	        
	        if(n-i+x==n) return 0;
	    }
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends