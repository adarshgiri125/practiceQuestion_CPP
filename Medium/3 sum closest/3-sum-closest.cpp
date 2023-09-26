//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int n, int x)
    {
        sort(a,a+n);
        int ans = INT_MAX;

        int sum = 0;
        for(int i = 0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            
            while( j < k){
               
                if(abs(a[i] + a[j] + a[k]- x ) < ans){
                   ans = abs(a[i] + a[j] + a[k] - x );
                   sum = a[i] + a[j] + a[k];
                   
                }
                if(abs((a[i] + a[j] + a[k]) - x ) == 0) return a[i] + a[j] + a[k];
                else if(a[i] + a[j] + a[k]  > x )
                   k--;
                else
                    j++;
                
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends