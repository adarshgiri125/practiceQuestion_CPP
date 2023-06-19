//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            sort(arr,arr+n);
            int i=0;
            int j=n-1;
            int diff=INT_MAX;
            int sum=0;
            int ans=-1;
            while(i<j)
            {
                sum=arr[i]+arr[j];
                if(sum<0)
                {
                    if(abs(0-sum)<diff)
                    {
                        diff=abs(0-sum);
                        ans=sum;
                    }
                    i++;
                }
                else
                {
                    if(abs(sum-0)<=diff)
                    {
                        diff=abs(sum-0);
                        ans=sum;
                    }
                    j--;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends