//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> nxtPer(vector<int>&arr,int n) {
      int idx = -1;
      
      for(int i = n-2;i>=0;--i) {
          if(arr[i] < arr[i+1]) {
              idx = i;
              break;
          }
      }
      
      if(idx == -1) {
          sort(begin(arr),end(arr));
          return arr;
      }
      
      for(int i = n-1;i > idx;--i) {
          if(arr[i] > arr[idx]) {
              swap(arr[i],arr[idx]);
              break;
          }
      }
      
      reverse(begin(arr) + idx + 1,end(arr));
      
      return arr;
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<int>initialArr = arr;
        sort(begin(initialArr),end(initialArr));
        
        vector<vector<int>>ans;
        ans.push_back(initialArr);
        
        vector<int>chk = initialArr;
        
        while(1) {
            vector<int>temp = nxtPer(chk,n);
            if(temp == initialArr) break;
            ans.push_back(temp);
            chk = temp;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends