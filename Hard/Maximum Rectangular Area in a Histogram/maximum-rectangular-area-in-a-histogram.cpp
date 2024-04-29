//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> right(n);
        vector<long long> left(n);
        
        stack<long long> s;
        stack<long long> s2;
        for(int i = 0; i<n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()) right[i] = -1;
            else right[i] = s.top();
            
            s.push(i);
        }
        for(int i = n-1; i>=0; i--){
            while(!s2.empty() && arr[s2.top()] >= arr[i]){
                s2.pop();
            }
            if(s2.empty()) left[i] = n;
            else left[i] = s2.top();
            
            s2.push(i);
        }
        
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long value = left[i] - right[i] - 1;
            long long temp = value * arr[i];
            ans = max(ans, temp);
        }
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends