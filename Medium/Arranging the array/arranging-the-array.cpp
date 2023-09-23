//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
        //   int i = 0;
        //   int j = n-1;
        //   while(i < n && j < n){
        //       if(arr[i] > 0 && arr[j] < 0){
        //           swap(arr[i],arr[j]);
        //       }
        //       while(arr[i] < 0 && i < n){
        //           i++;
        //       }
        //       while(arr[j] > 0 && j < n){
        //           j++;
        //       }
               
        //   }
        
            vector<int> store;
            for(int i = 0; i<n; i++){
                if(arr[i] < 0){
                    store.push_back(arr[i]);
                }
            }
         
            for(int i = 0 ; i<n; i++){
                if(arr[i] >= 0){
                    store.push_back(arr[i]);
                }
                // for(auto i : store) cout << i << " ";
                
                // cout << endl;
                if(store[i] != 1e9){
                     arr[i] = store[i];
                }
               
            }
            
            
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends