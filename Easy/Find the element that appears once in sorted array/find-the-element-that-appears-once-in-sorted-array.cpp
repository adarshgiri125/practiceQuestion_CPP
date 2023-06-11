//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int s=0;
        int e=n-1;
        int m=s+(e-s)/2;
        
        while(s<=e)
        {
            if(arr[m]==arr[m-1])
            {
                if((m-s+1)%2==0)
                s=m+1;
                else
                e=m;
            }
            
            else if(arr[m]==arr[m+1])
            {
                if((e-m+1)%2==0)
                e=m-1;
                else
                s=m;
            }
            
            else
            return arr[m];
            
            m=s+(e-s)/2;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends