//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int num[], int deno[])
    {
        
       
        unordered_map<double, int> frac;
        for(int i = 0; i<n; ++i) {
            double val = num[i] * 1.0 / deno[i];
            frac[val]++;
        }
        
        int cnt = 0;
        for(int i=0; i<n; ++i) {
            int val = deno[i] - num[i];
            double res = val * 1.0 / deno[i];
            
            frac[1.0*num[i]/deno[i]]--;
            if(frac.find(res) != frac.end()) cnt += frac[res];
        }
        
        return cnt;
        
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends