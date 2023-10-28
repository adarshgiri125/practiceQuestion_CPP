//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int count(int n){
        int count = 0;
        while(n > 0){
            if(n&1) count++;
            n = n >> 1;
        }
        return count;
    }
	int is_bleak(int n)
	{
	    
	    for(int i = n-32;i<=n;i++){
	        if(i + count(i) == n) return 0;
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