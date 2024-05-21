//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> func(vector<int> &arr, int lf, int rt, int x,int k){
        int l=abs(arr[lf]-x);
        int r=abs(arr[rt]-x);
        vector<int> ans;
        while(k--){
            if(lf<0)l=INT_MAX;
            if(rt>=arr.size())r=INT_MAX;
            if(l<r){
                ans.push_back(arr[lf--]);
                l=abs(arr[lf]-x);
            }
            else{
                ans.push_back(arr[rt++]);

                r=abs(arr[rt]-x);
            }
        }
        return ans;
        
    }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        int l=0;
        int r=arr.size()-1;
        int prev=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==x){
                return func(arr,mid-1,mid+1,x,k);
            }
            if(x>arr[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
            prev=mid;
        }
        if(arr[prev]>x){
            return func(arr,prev-1,prev,x,k);
            
        }
        return func(arr,prev,prev+1,x,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends