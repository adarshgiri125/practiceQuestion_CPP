//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        // your code here
        int mod = 1e9+7;
        int n = s.length();
        long long res = s[0]-'0';
        long long int pre[n];
        pre[0] = res;
        for(int i = 1; i < n; i++){
            pre[i] = ((i+1)*(s[i]-'0') + 10 * pre[i-1])%mod;
            res=(res+pre[i])%mod;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends