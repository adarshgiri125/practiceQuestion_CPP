//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod = 1e9 + 7;
    int padovanSequence(int n)
    {
       if (n == 0 || n == 1 || n == 2) {
            return 1;
        }

        // Create a dp array to store the Padovan numbers
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;

        // Fill the dp array using the recurrence relation
        for (int j = 3; j <= n; j++) {
            dp[j] = (dp[j - 2] + dp[j - 3]) % mod;
        }

        // Return the nth Padovan number
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
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends