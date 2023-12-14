//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    #define ll long long
    int mod=1e9+7;
    public:
    ll help(int n,int& k,vector<ll>& memo)
    {
        //base cases
        if(n==1)
        return k;
        
        if(n==2)
        return static_cast<long long>(k)*k;
        
        //memo check
        if(memo[n]!=-1)
        return memo[n];
        
        //recursive calls
        //small calculation
        ll same=(help(n-2,k,memo)*(k-1))%mod;
        ll diff=(help(n-1,k,memo)*(k-1))%mod;
        
        return memo[n]=(same+diff)%mod;
    }
    long long countWays(int n, int k){
        vector<ll> memo(n+1,-1);
        ll ans=help(n,k,memo)%mod;
        
        return ans;
    }

};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends