//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
            //code here.
            stack<int> s;
            s.push(n);
            int ans = 0;
            
            while(!s.empty()){
                int ele = s.top();
                s.pop();
                int f = ele / 3;
                int se = ele / 2;
                int t = ele / 4;
                
                int val = f + se + t;
                if(val > ele){
                    s.push(f);
                    s.push(se);
                    s.push(t);
                }
                else{
                    ans += ele;
                }
                
            }
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
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends