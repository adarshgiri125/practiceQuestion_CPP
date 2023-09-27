//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
       
    //   int j = n-1;
    //   int sum = 0;
    //   vector<int> ans;
    //   if(n >= m){
    //       for(int i = 0; i<n; i++){
    //             sum = abs(arr[i] + brr[j]);
    //             if(sum > x){
    //               while(j >= 0 && sum > x){
    //                   j--;
    //               }
    //               sum = arr[i] + brr[j];
    //               ans.push_back(arr[i]);
    //               ans.push_back(brr[j]);
    //               break;
    //           }
            
    //       }
           
    //   }
    //   else{
           
    //       for(int i = 0; i<m; i++){
    //           sum = abs(arr[i] + brr[j]);
    //           if(sum > x){
    //               while( j >= 0 && sum > x) {
    //                   j--;
    //               }
    //               sum = arr[i] + brr[j];
    //               ans.push_back(arr[i]);
    //               ans.push_back(brr[j]);
    //               break;
                   
    //           }
            
    //       }
           
    //   }
       
    //   return ans;
        vector<int>ans(2);
        int mn=INT_MAX;
        int i=0,j=m-1;
        while(i<n && j>=0)
        {
            int sum=arr[i]+brr[j];
            int diff=abs(sum-x);
            if(diff<mn)
            {mn=diff;
            ans[0]=arr[i];
            ans[1]=brr[j];
            }
            if(sum>x)
            j--;
            else
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends