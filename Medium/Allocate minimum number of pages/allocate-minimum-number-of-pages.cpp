//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int mid, int arr[], int m, int n){
        int add = 0;
        int student = 1;
        for(int i = 0; i<n; i++){
            if(add + arr[i] <= mid){
                add += arr[i];
            }
            else{
                student++;
                if(student > m || arr[i] > mid){
                    return false;
                }
                add = arr[i];
            }
        }
        return true;
    }
    int findPages(int arr[], int n, int m) 
    {
        if(n < m){
            return -1;
        }
        int i = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        
        int s = 0;
        int e = sum;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while(s <= e){
            
            if(isPossible(mid,arr,m,n)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends