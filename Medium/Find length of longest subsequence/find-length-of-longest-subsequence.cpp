//{ Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

int maxSubsequenceSubstring(string X, string Y, int N, int M){
   //code
   int ans=0;
   for(int j=0;j<M;j++)
   {
       int count=0;
       int k=j;
       for(int i=0;i<N;i++)
       {
           if(X[i]==Y[k])
           {count++;
           k++;
           }
           ans=max(ans,count);
       }
   }
   return ans;
}