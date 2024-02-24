//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
  long long int count(long long int n)
    {
        vector<int> arr({3, 5, 10});
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0;i < 3;++i)
        for(int j = arr[i];j <= n;++j)
            if(dp[j - arr[i]] != 0)
                dp[j] += dp[j - arr[i]];
    return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends