//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        
        // int j = n-1;
        // int ele = 0;
        // for(int i = 0; i<n-1; i++){
            
        //     if(arr[i] == arr[i+1]){
        //         swap(arr[i+1],arr[j]);
        //         ele = arr[i+1];
        //         j--;
            
        //     }
        // }
        
        // for(int i = 0; i<n; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        
        // int count = 1;
        // for(int i = 0; i<n; i++){
        //     if(arr[i] == ele){
        //         break;
        //     }
        //     count++;
        // }
        
        // sort(arr,arr+count);
        // return count;
        
        
        // code here
        int c = 0;
        int j = 0;
        for(int i = 0;i<n;i++){
           while(i+1 < n && a[i] == a[i+1]){
               c++;
               i++;
           }
           a[j] = a[i];
           j++;
        }
        return n-c;
    
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends