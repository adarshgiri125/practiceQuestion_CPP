//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int findsqrt(long long int n)
  {
      if(n==0 || n==1) return n;
      int left=0,right=n/2;
      long long int ans;
      while(left<=right)
      {
          long long int mid=(left+right)/2;
          if(mid*mid==n) return mid;
          else if(mid*mid<=n){
              left=mid+1;
              ans=mid;
          }
          else{
              right=mid-1;
          }
      }
      return ans;
  }
    long long int floorSqrt(long long int n) {
        return findsqrt(n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends